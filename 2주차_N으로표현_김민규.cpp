#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <cstring>

constexpr int MAX_COUNT = 8;
constexpr int LIMIT = 32000;

struct Data
{
	int step;
	int number;

	Data(const int& step, const int& number)
	{
		this->step = step;
		this->number = number;
	}
};

inline bool isOutOfBounding(const int& number)
{
	return number < 0 || number > LIMIT;
}

int solution(int N, int number)
{
	char dp[LIMIT + 1];

	memset(dp, 127, LIMIT + 1);
	for (register int i = N, step = 1; i <= LIMIT; i = i * 10 + N, ++step) {
		dp[i] = step;
	}

	// construct tree by queue
	std::stack<Data> s;
	for (register int i = N, step = 1; step <= 6; i = i * 10 + N, ++step) {
		s.push(Data(step, i));
	}

	while (!s.empty()) {
		register Data data = s.top();
		s.pop();

		for (register int i = N, step = 1; data.step + step <= MAX_COUNT; i = i * 10 + N, ++step) {
			register int result;

			result = data.number + i;
			if (!isOutOfBounding(result)) {
				if (step + data.step < dp[result]) {
					dp[result] = step + data.step;
					s.push(Data(dp[result], result));
				}
			}

			result = data.number * i;
			if (!isOutOfBounding(result)) {
				if (step + data.step < dp[result]) {
					dp[result] = step + data.step;
					s.push(Data(dp[result], result));
				}
			}

			result = data.number / i;
			if (!isOutOfBounding(result)) {
				if (step + data.step < dp[result]) {
					dp[result] = step + data.step;
					s.push(Data(dp[result], result));
				}
			}

			result = data.number - i;
			if (!isOutOfBounding(result)) {
				if (step + data.step < dp[result]) {
					dp[result] = step + data.step;
					s.push(Data(dp[result], result));
				}
			}
		}
	}

	dp[number] = std::min(dp[number - 1] + 2, dp[number] + 0);
	dp[number] = std::min(dp[number + 1] + 2, dp[number] + 0);

	return dp[number] > MAX_COUNT ? -1 : dp[number];
}

int main()
{
	register int N, number;

	scanf("%d %d", &N, &number);
	printf("%d \n", solution(N, number));

	return 0;
}