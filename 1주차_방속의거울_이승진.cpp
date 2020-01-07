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

class Position {
public:
	int x = 0;
	int y = 0;

	bool operator==(Position otherPos) {
		if (this->x == otherPos.x && this->y == otherPos.y)
			return true;
		return false;
	}

	Position(const int x, const int y) {
		this->x = x;
		this->y = y;
	}
};

const Position UP = Position(-1, 0);
const Position DOWN = Position(1, 0);
const Position LEFT = Position(0, -1);
const Position RIGHT = Position(0, 1);

Position NextPos(const int roomId, Position beforePos) {
	if (roomId == 0)
		return beforePos;
	else if (roomId == 1) {
		if (beforePos == UP)
			return RIGHT;
		else if (beforePos == DOWN)
			return LEFT;
		else if (beforePos == LEFT)
			return DOWN;
		else if (beforePos == RIGHT)
			return UP;
	}
	else if (roomId == 2) {
		if (beforePos == UP)
			return LEFT;
		else if (beforePos == DOWN)
			return RIGHT;
		else if (beforePos == LEFT)
			return UP;
		else if (beforePos == RIGHT)
			return DOWN;
	}
	else
		return LEFT;
}

bool IsOut(const Position pos, const int size) {
	if (pos.x < 0 || pos.y < 0 || pos.x >= size || pos.y >= size)
		return true;
	return false;
}

int GetRoomIdx(const Position pos, const int size) {
	return pos.x * size + pos.y;
}

int Result(vector<int> room, int size) {
	Position movePos = RIGHT;
	Position currentPos = Position(0, 0);

	int count = 0;
	int roomIdx = 0;

	//Save what already checked room
	vector<bool> roomPassVec(size * size, false);

	while (IsOut(currentPos, size) == false)
	{
		roomIdx = GetRoomIdx(currentPos, size);
		if (roomPassVec[roomIdx] == false && room[roomIdx] != 0)
		{
			roomPassVec[roomIdx] = true;
			count++;
		}

		movePos = NextPos(room[roomIdx], movePos);
		currentPos.x += movePos.x;
		currentPos.y += movePos.y;
	}

	return count;
}

int main(int argc, char** argv)
{
	int T, test_case;
	/*
	   The freopen function below opens input.txt file in read only mode, and afterward,
	   the program will read from input.txt file instead of standard(keyboard) input.
	   To test your program, you may save input data in input.txt file,
	   and use freopen function to read from the file when using cin function.
	   You may remove the comment symbols(//) in the below statement and use it.
	   Use #include<cstdio> or #include <stdio.h> to use the function in your program.
	   But before submission, you must remove the freopen function or rewrite comment symbols(//).
	 */

	cin >> T;
	vector<int> roomVec;
	for (test_case = 0; test_case < T; test_case++)
	{
		int size = 0;
		cin >> size;

		roomVec.resize(size * size, 0);

		for (int i = 0; i < size; i++) {
			string line;
			cin >> line;
			for (int j = 0; j < size; j++)
				roomVec[GetRoomIdx(Position(i, j), size)] = (int)(line[j] - 48);
		}

		Answer = Result(roomVec, size);
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}