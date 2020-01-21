#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> memoization;

int Answer;
int memoHeightMax = 31623; // 31623^2 > 10^9�̶� 31623���ʹ� �ʿ� ����.
int memoWidthMax = 31;	   // 2^31 > 10^9�� 31���ʹ� �ʿ� ����.
int NMax = 1000000000;	   //10^9

//int �����÷ο� ������ ���� long long ���
//��ȭ�� ��� ����
//f(i,j) = i^j + i^(j-1) + ...+ i^1 + 1
//       = (i^(j+1) - 1)/(i-1)
long long explicitResultOf(long long i, long long j)
{
	return (pow(i, j + 1) -1) / (i - 1);
}

//memoization �ʱ�ȭ
//memoization[i][j] = f(i,j)
void initializMemoization() 
{
	memoization = *(new vector<vector<int>>(memoHeightMax, vector<int>(memoWidthMax, -1)));

	for (int i = 2; i < memoHeightMax; i++)
	{
		memoization[i][0] = 1;
		for (int j = 1; j < memoWidthMax; j++)
		{
			long long temp = explicitResultOf(i, j);
			
			// f(i,j) > 10^9�̸� ���� �ٷ� �Ѿ
			if (temp > NMax)
			{
				memoization[i].resize(j);
				break;
			}			
			memoization[i][j] = (int) temp;
		}
	}
}

int solve(int target) 
{
	//����ó��
	if (target == 1)
		return 2;
	if (target == 2)
		return 3;

	//N = f(i,j) * c ���°� ������ ��� N�� i�� ���� ���ϼ��� �ȴ�.(2<=i, 1<=j, 0 < c < i. i,j,c�� ����)
	//i������ ǥ�� ������ ���ϼ��� 1, 11, 111, ... 2, 22, 222, ... 3, 33, 333, ...... i-1, (i-1)(i-1),(i-1)(i-1)(i-1),... �̴�
	//�׸��� ���⿡�� i ���� ���� � �� c�� ���� ccc...ccc �� 111...111 * c�� ����.
	//���� N�� i������ ccc....ccc��� ǥ���ȴٸ� N�� (i���� 111...111) * c �� ���� ���̴�.
	//�׷��Ƿ� memoization[i][j] �� N�� ����� �ִٸ�, �� i�� ���� N�� i�� ���� ���ϼ���.

	//f(i,j) > 10^9�̻��� ���� �� ������� �׽�Ʈ �غ� �ʿ䰡 ���� ������, i^2 > 10^9�� 31623 �̻��� i�� �׽�Ʈ �غ� �ʿ䰡 ����,
	//i^j > 10^9�� ����� i,j�� �׽�Ʈ�غ� �ʿ䰡 ����.
	//�ð����⵵ : O(sqrt(N) * 31)
	for (int i = 2; i < memoHeightMax; i++)
	{
		int width = memoization[i].size();
		for (int j = 1; j < width; j++)
		{
			if (target % memoization[i][j] == 0 &&
				(target / memoization[i][j] < i))
				return i;
		}
	}

	//N�� �� 31623 �̻��� � ���� k�� ���Ͽ�, k�� N�� ����̸� N�� k-1�� ���� ���ϼ���.
	//k�� N�� ����̸� 31622 ������ � ���� i�� ���ؼ� i * k = N�̴�.
	//k * k > 10^9 �̱� ������, k�� 31622 ������ � ���� ���ؾ� N�� �� �� �ִ� ���̴�.
	//�ð����⵵ : O(sqrt(N) * 31)
	for (int i = memoHeightMax - 1; i >= 2; i--)
	{
		if (target % i == 0)
			return (target / i) - 1;
	}

	return target - 1;
}

void test()
{
	for (int i = 0; i < memoization.size(); i++)
	{
		cout << i << ":";
		for (int j = 0; j < memoization[i].size(); j++)
		{
			cout << memoization[i][j] << "\t";
		}
		cout << endl;
	}
}

void test2()
{
	for (int i = 800000000; i < 1000000000; i++)
		cout << i << " : " << solve(i) << endl;
}


int main(int argc, char** argv)
{
	int T, test_case;
	
	initializMemoization();
	//test();
	//test2();
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int target;
		cin >> target;
		Answer = solve(target);

		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}