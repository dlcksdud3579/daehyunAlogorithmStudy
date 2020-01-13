#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

constexpr int MAX_COUNT = 2000;

static int dp[MAX_COUNT + 1][MAX_COUNT + 1];

int solution(vector<int> left, vector<int> right) {
	const int size = left.size();
	int answer = 0;

	for (register int i = 0; i < size; ++i) {
		for (register int j = 0; j < size; ++j) {
			if (left[i] > right[j]) {
				dp[i][j + 1] = std::max(dp[i][j] + right[j], dp[i][j + 1]);
			}
			else {
				dp[i + 1][j] = std::max(dp[i][j], dp[i + 1][j]);
				dp[i + 1][j + 1] = std::max(dp[i][j], dp[i + 1][j + 1]);
			}
		}
	}

	for (register int i = 0; i <= size; ++i) {
		for (register int j = 0; j <= size; ++j) {
			answer = std::max(dp[i][j], answer);
		}
	}

	return answer;
}

int main()
{
	std::vector<int> left;
	std::vector<int> right;
	register int n;
	scanf("%d", &n);

	left.resize(n >> 1);
	right.resize(n >> 1);

	for (register int i = 0; i < (n >> 1); ++i) {
		scanf("%d", &left[i]);
	}

	for (register int i = 0; i < (n >> 1); ++i) {
		scanf("%d", &right[i]);
	}

	printf("%d \n", solution(left, right));

	return 0;
}