#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>

static int Answer;
static int N;

void solve()
{
	switch (N) {
	case 1:
		Answer = 2;
		return;
	case 2:
		Answer = 3;
		return;
	}

	const int until = sqrt(N);
	Answer = N - 1;
	for (register int b = 2; b <= until; ++b) {
		const int digit = N % b;
		register int temp_N = N / b;
		register bool found = true;

		if (digit == 0) {
			continue;
		}

		while (temp_N) {
			if (temp_N % b != digit) {
				found = false;
				break;
			}
			temp_N /= b;
		}

		if (found) {
			Answer = b;
			break;
		}
	}
	if (Answer == N - 1) {
		for (register int i = until; i > 0; --i) {
			if (N % i > 0) {
				continue;
			}

			const int base = N / i - 1;
			if (base > i) {
				Answer = base;
				return;
			}
		}
	}
}

int main(int argc, char** argv)
{
	register int T;

	setbuf(stdout, NULL);
	scanf("%d", &T);

	for (register int test_case = 1; test_case <= T; ++test_case)
	{	
		scanf("%d", &N);

		solve();

		printf("Case #%d\n%d\n", test_case, Answer);
	}

	return 0;
}