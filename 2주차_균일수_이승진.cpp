/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
using namespace std;

int Answer;

int Solve(const int& question) {
	if (question == 1 || question == 3)
		return 2;
	else if (question == 2)
		return 3;

	for (int i = 2; i * i < question; ++i) {
		int quotient = question;
		int remainder = question % i;
		bool result = true;

		while (quotient > 0) {
			if (quotient % i != remainder) {
				result = false;
				break;
			}

			quotient /= i;
		}

		if (result == true)
			return i;
	}

	int answer = question;
	for (int i = 1; i * i < question; ++i) {
		if (question % i != 0)
			continue;

		int tempAnswer = question / i - 1;
		if (i < tempAnswer && tempAnswer < answer)
			answer = tempAnswer;
	}

	return answer;
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

	 // freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		int question = 0;
		cin >> question;

		Answer = Solve(question);
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