#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <climits>

constexpr int MAX_SIZE = 200;

static long long inputX[MAX_SIZE];
static long long inputY[MAX_SIZE];
static long long Answer = 0;

inline long long getLength(const long long& a, const long long& b, const long long& x)
{
	register long long lhs = llabs(a - x);
	register long long rhs = llabs(b - x);
	return lhs < rhs ? lhs : rhs;
}

void solve(const int& N)
{
	std::vector<long long> sortedX, sortedY;
	
	sortedX.resize(MAX_SIZE); 
	sortedY.resize(MAX_SIZE);
	
	std::copy(inputX, inputX + MAX_SIZE, sortedX.begin());
	std::copy(inputY, inputY + MAX_SIZE, sortedY.begin());

	std::sort(sortedX.begin(), sortedX.end());
	std::sort(sortedY.begin(), sortedY.end());

	sortedX.erase(std::unique(sortedX.begin(), sortedX.end()), sortedX.end());
	sortedY.erase(std::unique(sortedY.begin(), sortedY.end()), sortedY.end());

	register long long xmax = LLONG_MAX;
	register long long ymax = LLONG_MAX;
	
	// 1. 해당 점이 정답인 경우
	for (auto& iter : sortedX) {
		register long long temp = 0;
		for (register int i = 0; i < N; ++i) {
			temp = std::max(temp, getLength(inputX[(i << 1)], inputX[(i << 1) + 1], iter));
		}
		xmax = std::min(temp, xmax);
	}
	for (auto& iter : sortedY) {
		register long long temp = 0;
		for (register int i = 0; i < N; ++i) {
			temp = std::max(temp, getLength(inputY[(i << 1)], inputY[(i << 1) + 1], iter));
		}
		ymax = std::min(temp, ymax);
	}

	// 2. 중점이 정답인 경우
	const int xsize = sortedX.size();
	for (register int i = 0; i < xsize; ++i) {
		for (register int j = i + 1; j < xsize; ++j) {
			register long long temp = 0;
			const long long half = (sortedX[i] + sortedX[j]) >> 1;
			
			for (register int i = 0; i < N; ++i) {
				temp = std::max(temp, getLength(inputX[(i << 1)], inputX[(i << 1) + 1], half));
			}
			xmax = std::min(temp, xmax);
		}
	}

	const int ysize = sortedY.size();
	for (register int i = 0; i < ysize; ++i) {
		for (register int j = i + 1; j < ysize; ++j) {
			register long long temp = 0;
			const long long half = (sortedY[i] + sortedY[j]) >> 1;

			for (register int i = 0; i < N; ++i) {
				temp = std::max(temp, getLength(inputY[(i << 1)], inputY[(i << 1) + 1], half));
			}
			ymax = std::min(temp, ymax);
		}
	}

	Answer = std::max(xmax, ymax);
}

int main()
{
	int T, test_case;

	setbuf(stdout, nullptr);
	scanf("%d", &T);
	
	for (register int test_case = 1; test_case <= T; ++test_case) {
		register int N;
		scanf("%d", &N);

		const int bytes = sizeof(long long) * MAX_SIZE;
		memset(inputX, 0, bytes);
		memset(inputY, 0, bytes);

		for (register int i = 0; i < N; ++i) {
			scanf("%d %d %d %d", &inputX[(i << 1)], &inputY[(i << 1)], &inputX[(i << 1) + 1], &inputY[(i << 1) + 1]);
			inputX[(i << 1)]	 <<= 1;
			inputX[(i << 1) + 1] <<= 1;
			inputY[(i << 1)]	 <<= 1;
			inputY[(i << 1) + 1] <<= 1;
		}
		solve(N);
		if (Answer % 2) {
			printf("Case #%d\n%.1f\n", test_case, Answer * 0.5f);
		}
		else {
			printf("Case #%d\n%d\n", test_case, (Answer >> 1));
		}
	}

	return 0;
}