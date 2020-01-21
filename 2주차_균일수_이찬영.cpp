/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;



int Answer;

bool change_base(int n, int b)
{
	int r = -1,preR = -1;
	while(n > 0)
	{
		preR = r;
		r = n % b; //
		if (preR != -1 && preR != r)
			return false;
		n /= b;
	}

	
	//if (n > 0) change_base(n, b);
	 //printf("%d,", r);       // 10진수 이하 

	 return true;
}

int solution(int number)
{

	for (int i = 2; i < 32; i++)
	{
		if (change_base(number, i))
			return i;
		
	}
	return 0;
}




int main(int argc, char** argv)
{
	int T, test_case, number;
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
		cin >> number;
		
		Answer = solution(number);
		 /////////////////////////////////////////////////////////////////////////////////////////////

		 // Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}