/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <string>


using namespace std;

int Answer;

//빛의 방향
class Direction { 
public:
	int x; 
	int y; 

	Direction(int x, int y) {
		this->x = x;
		this->y = y;
	}

	bool operator==(Direction other)
	{
		if (this->x != other.x)
			return false;
		if (this->y != other.y)
			return false;
		return true;
	}
};

const Direction LEFT = { -1,0 };
const Direction RIGHT = { 1,0 };
const Direction UP = { 0,-1 };
const Direction DOWN = { 0,1 };

//방들 안에 속해있는가(건물 밖을 벗어나지 않았는가) 체크하는 함수
bool isinBound(int x, int y, int width) 
{
	if (x >= width)
		return false;
	if (x < 0)
		return false;
	if (y >= width)
		return false;
	if (y < 0)
		return false;
	return true;
}

//방에 거울이 있는가 체크하는 함수
bool isRoomMirrored(const vector<vector<int>>& map, int x, int y) 
{
	if (map[y][x] > 0)
		return true;
	return false;
}

//빛이 dir 방향이고, 방이 mirror일 때, 빛이 어느 방향으로 가는가 구하는 함수
Direction newDir(int mirror, Direction dir)
{
	//빈 방일 경우 방향 변화 없음
	if (mirror == 0)
		return dir;
	else if (mirror == 1)	//타입1 거울방일 경우
	{
		if (dir == LEFT)
			return DOWN;
		else if (dir == RIGHT)
			return UP;
		else if (dir == UP)
			return RIGHT;
		else if (dir == DOWN)
			return LEFT;
	}
	else  //타입2 거울방인 경우
	{
		if (dir == LEFT)
			return UP;
		else if (dir == RIGHT)
			return DOWN;
		else if (dir == UP)
			return LEFT;
		else if (dir == DOWN)
			return RIGHT;
	}
}

//하나의 테스트 케이스 해결
int solve(const vector<vector<int>>& map)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int width = map.size();
	Direction dir = RIGHT;

	// 빛이 이미 지나온 방인지 확인하기 위한 맵
	vector<vector<bool>> hasPassed(width, vector<bool>(width, false));

	while (isinBound(x, y, width))
	{
		//거울이 있는 방이고, 지나오지 않았던 방이면 카운트 + 1
		if (isRoomMirrored(map, x, y))
		{
			if (!hasPassed[y][x])
			{
				count++;
				hasPassed[y][x] = true;
			}
		}
			
		//방향 전환
		dir = newDir(map[y][x], dir);

		//이동
		x += dir.x;
		y += dir.y;
	}
	return count;
}

int main(int argc, char** argv)
{
	int T, test_case;

	  //freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		Answer = 0;

		/*********************입력 데이터 파싱********************/
		vector<vector<int>> map;
		int width;

		cin >> width;
		map.resize(width, vector<int>(width, 0));

		for (int i = 0; i < width; i++)
		{
			string inputLine;
			cin >> inputLine;

			for (int j = 0; j < width; j++)
			{
				char ch;
				ch = inputLine[j];
				map[i][j] = (int)(ch - 48);
			}
		}
		//////////////////////////////////////////////////////////

		Answer = solve(map);

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	//system("pause");

	return 0;//Your program should return 0 on normal termination.
}