/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#pragma warning(disable : 4996)warning pragma

#include <iostream>
#include <string>

using namespace std;

int* map;
int* check;
int Answer;

void Mirror(int *Dir, int mir) // cDir = 현재 방향 mir = 거울 번호
{
	switch (mir)
	{
	case 0:
		break;
	case 1:
		switch (*Dir)
		{
		case 1:
			*Dir = 4;
			break;
		case 2:
			*Dir = 3;
			break;
		case 3:
			*Dir = 2;
			break;
		case 4:
			*Dir = 1;
			break;
		}
		break;
	case 2:
		switch (*Dir)
		{
		case 1:
			*Dir = 2;
			break;
		case 2:
			*Dir = 1;
			break;
		case 3:
			*Dir = 4;
			break;
		case 4:
			*Dir = 3;
			break;
		}
		break;
	default:
		break;
	}
}

bool  move(int *pos, int dir ,int n)
{
	
	switch (dir)
	{
	case 1:
		if (*pos % n == n-1)
			return false;
		 *pos+=1;

		break;
	case 2:
		*pos+=n;
		if (*pos >= n * n)
			return false;

		break;
	case 3:
		if (*pos % n == 0)
			return false;
		*pos-=1;
		break;
	case 4:
		*pos-=n;
		if (*pos < 0)
			return false;
		break;
	}
	return true;
	
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

	freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		int n = 0;
		int dir = 1;
		int pos = 0;

		cin >> n;
		map = new int[n*n];
		check = new int[n * n]{0,};
		for (int i = 0; i < n; i++)
		{
			string temp;
			cin >> temp;
			for (int j = 0; j < n; j++)
			{
				map[i * n + j] = stoi(temp.substr(j, 1));
			}
		}
		while (1)
		{
			if(map[pos] != 0)
				check[pos] = 1;
			Mirror(&dir, map[pos]);
			if (!move(&pos, dir, n))
				break;
		}

		for (int i = 0; i < n * n; i++)
			Answer += check[i];
		


		delete[n*n] map;
		delete[n*n] check;
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}