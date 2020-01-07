#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <utility>

constexpr char NONE = '0';
constexpr char L2R  = '1';
constexpr char R2L  = '2';

constexpr int ARRAY_SIZE = 1000 * 1000;

static int answer;
static int n;
static char visit[ARRAY_SIZE];
static char room[ARRAY_SIZE + 3];

struct Point {
	int x;
	int y;

	Point(const int& x, const int& y) {
		this->x = x;
		this->y = y;
	}
};

// 1 : swap & change sign
// 2 : swap
inline void changeVector(Point& p, const char& type) 
{
	switch (type) {
	case L2R:
		p.x = -p.x;
		p.y = -p.y;
		break;
	case NONE:
		return;
	}
	std::swap(p.x, p.y);
}

inline bool isOutOfBounding(Point& point) 
{
	return point.x < 0 || point.x >= n || point.y < 0 || point.y >= n;
}

void solve()
{
	register Point from(-1, 0);
	register Point to(0, 0);

	while (!isOutOfBounding(to)) {
		register Point v(to.x - from.x, to.y - from.y);
		register int idx = n * to.y + to.x;

		if (room[idx] > NONE) {
			visit[idx] = 1;
		}

		changeVector(v, room[idx]);
		memcpy(&from, &to, sizeof(Point));
		to.x += v.x;
		to.y += v.y;
	}

	const int until = n * n;
	for (register int i = 0; i < until; ++i) {
		answer += visit[i];
	}
}

int main()
{
	register int t;

	setbuf(stdout, nullptr);
	scanf("%d", &t);

	for (register int test_case = 0; test_case < t; ++test_case) {		
		memset(visit, 0, ARRAY_SIZE);
		memset(room, 0, ARRAY_SIZE + 3);
		answer = 0;

		scanf("%d\n", &n);
		for (register int i = 0; i < n; ++i) {
			fgets(&room[i * n], 1003, stdin);
		}
		solve();

		printf("Case #%d\n%d\n", test_case + 1, answer);
	}

	return 0;
}