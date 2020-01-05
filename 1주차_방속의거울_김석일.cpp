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

//���� ����
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

//��� �ȿ� �����ִ°�(�ǹ� ���� ����� �ʾҴ°�) üũ�ϴ� �Լ�
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

//�濡 �ſ��� �ִ°� üũ�ϴ� �Լ�
bool isRoomMirrored(const vector<vector<int>>& map, int x, int y) 
{
	if (map[y][x] > 0)
		return true;
	return false;
}

//���� dir �����̰�, ���� mirror�� ��, ���� ��� �������� ���°� ���ϴ� �Լ�
Direction newDir(int mirror, Direction dir)
{
	//�� ���� ��� ���� ��ȭ ����
	if (mirror == 0)
		return dir;
	else if (mirror == 1)	//Ÿ��1 �ſ���� ���
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
	else  //Ÿ��2 �ſ���� ���
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

//�ϳ��� �׽�Ʈ ���̽� �ذ�
int solve(const vector<vector<int>>& map)
{
	int x = 0;
	int y = 0;
	int count = 0;
	int width = map.size();
	Direction dir = RIGHT;

	// ���� �̹� ������ ������ Ȯ���ϱ� ���� ��
	vector<vector<bool>> hasPassed(width, vector<bool>(width, false));

	while (isinBound(x, y, width))
	{
		//�ſ��� �ִ� ���̰�, �������� �ʾҴ� ���̸� ī��Ʈ + 1
		if (isRoomMirrored(map, x, y))
		{
			if (!hasPassed[y][x])
			{
				count++;
				hasPassed[y][x] = true;
			}
		}
			
		//���� ��ȯ
		dir = newDir(map[y][x], dir);

		//�̵�
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

		/*********************�Է� ������ �Ľ�********************/
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