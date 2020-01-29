#include <iostream>
#include <vector>
#include <algorithm>
#define INT_MAX 1000000000

using namespace std;

int Answer;
vector<int> xCoords;
vector<int> yCoords;
int N;

int minDFBOfMaxDfB_x()
{
	int minDFBOfMaxes = INT_MAX;
	//��� ������ ���� �׽�Ʈ
	for (int i = 0; i < N * 2; i++)
	{
		//i������ ��� ������ ���� �׽�Ʈ
		for (int j = i + 1; j < N * 2; j++)
		{
			//�� ������ �߰�����
			int mid = (xCoords[i] + xCoords[j]) / 2;
			int tempMaxDFB = -1;

			//�߰������� �� ���а��� x���� �����Ÿ�
			for (int k = 0; k < N ; k ++)
			{
				int temp = min(abs(xCoords[k * 2] - mid), abs(xCoords[k * 2 + 1] - mid));
				tempMaxDFB = max(tempMaxDFB, temp);
			}

			minDFBOfMaxes = min(minDFBOfMaxes, tempMaxDFB);
		}
	}

	return minDFBOfMaxes;
}


int minDFBOfMaxDfB_y()
{
	int minDFBOfMaxes = INT_MAX;
	//��� ������ ���� �׽�Ʈ
	for (int i = 0; i < N * 2; i++)
	{
		//i������ ��� ������ ���� �׽�Ʈ
		for (int j = i + 1; j < N * 2; j++)
		{
			//�� ������ �߰�����
			int mid = (yCoords[i] + yCoords[j]) / 2;
			int tempMaxDFB = -1;

			//�߰������� �� ���а��� x���� �����Ÿ�
			for (int k = 0; k < N; k++)
			{
				int temp = min(abs(yCoords[k * 2] - mid), abs(yCoords[k * 2 + 1] - mid));
				tempMaxDFB = max(tempMaxDFB, temp);
			}

			minDFBOfMaxes = min(minDFBOfMaxes, tempMaxDFB);
		}
	}

	return minDFBOfMaxes;
}

int solve()
{	
	//x�� ���� �����Ÿ� ����, y�� ���� �����Ÿ� ���� ���ϸ� ��.

	//x�� ���� �׽�Ʈ
	int xMin = minDFBOfMaxDfB_x();

	//y�� ���� �׽�Ʈ
	int yMin = minDFBOfMaxDfB_y();

	int ans = max(xMin, yMin);

	return ans;
}

void parseInput()
{
	cin >> N;
	xCoords.resize(N * 2, -1);
	yCoords.resize(N * 2, -1);

	for (int i = 0; i < N; i++)
	{
		cin >> xCoords[i * 2];
		cin >> yCoords[i * 2];
		cin >> xCoords[(i * 2) + 1];
		cin >> yCoords[(i * 2) + 1];

		xCoords[i * 2] *= 2;
		yCoords[i * 2] *= 2;
		xCoords[(i * 2) + 1] *= 2;
		yCoords[(i * 2) + 1] *= 2;
	}
}

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		parseInput();
		Answer = solve();

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer / 2;
		if (Answer % 2 != 0) cout << ".5";
		cout << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}