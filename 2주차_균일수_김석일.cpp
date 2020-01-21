#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> memoization;

int Answer;
int memoHeightMax = 31623; // 31623^2 > 10^9이라서 31623부터는 필요 없음.
int memoWidthMax = 31;	   // 2^31 > 10^9라서 31부터는 필요 없음.
int NMax = 1000000000;	   //10^9

//int 오버플로우 방지를 위해 long long 사용
//점화식 결과 도출
//f(i,j) = i^j + i^(j-1) + ...+ i^1 + 1
//       = (i^(j+1) - 1)/(i-1)
long long explicitResultOf(long long i, long long j)
{
	return (pow(i, j + 1) -1) / (i - 1);
}

//memoization 초기화
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
			
			// f(i,j) > 10^9이면 다음 줄로 넘어감
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
	//예외처리
	if (target == 1)
		return 2;
	if (target == 2)
		return 3;

	//N = f(i,j) * c 형태가 가능한 경우 N은 i에 대해 균일수가 된다.(2<=i, 1<=j, 0 < c < i. i,j,c는 정수)
	//i진수로 표현 가능한 균일수는 1, 11, 111, ... 2, 22, 222, ... 3, 33, 333, ...... i-1, (i-1)(i-1),(i-1)(i-1)(i-1),... 이다
	//그리고 여기에서 i 보다 작은 어떤 수 c에 대해 ccc...ccc 는 111...111 * c와 같다.
	//만일 N이 i진수로 ccc....ccc라고 표현된다면 N은 (i진수 111...111) * c 와 같은 것이다.
	//그러므로 memoization[i][j] 중 N의 약수가 있다면, 그 i에 대해 N은 i에 대해 균일수다.

	//f(i,j) > 10^9이상인 경우는 이 방법으로 테스트 해볼 필요가 없기 때문에, i^2 > 10^9인 31623 이상의 i는 테스트 해볼 필요가 없고,
	//i^j > 10^9인 경우의 i,j도 테스트해볼 필요가 없다.
	//시간복잡도 : O(sqrt(N) * 31)
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

	//N에 과 31623 이상의 어떤 정수 k에 대하여, k가 N의 약수이면 N은 k-1에 대해 균일수다.
	//k가 N의 약수이면 31622 이하의 어떤 정수 i에 대해서 i * k = N이다.
	//k * k > 10^9 이기 때문에, k는 31622 이하의 어떤 수와 곱해야 N이 될 수 있는 것이다.
	//시간복잡도 : O(sqrt(N) * 31)
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