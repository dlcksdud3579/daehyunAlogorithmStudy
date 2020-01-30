#define _CRT_SECURE_NO_WARNINGS
/*
You should use the statndard input/output

in order to receive a score properly.

Do not use file input and output

Please be very careful.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>



using namespace std;

constexpr int MAX_SIZE = 200;
long long xpoint[MAX_SIZE];
long long ypoint[MAX_SIZE];
long long Answer;
int n;

void read()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		xpoint[i*2] = temp*2;
		cin >> temp;
		ypoint[i * 2] = temp * 2;
		cin >> temp;
		xpoint[i * 2+1] = temp * 2;
		cin >> temp;
		ypoint[i * 2 + 1] = temp * 2;
	}

}
int solve()
{
	vector<int> xsort, ysort;
	long long xmax = LLONG_MAX;
	long long ymax = LLONG_MAX;

	xsort.resize(MAX_SIZE);
	ysort.resize(MAX_SIZE);

	std::copy(xpoint, xpoint + MAX_SIZE, xsort.begin());
	std::copy(ypoint, ypoint + MAX_SIZE, ysort.begin());

	std::sort(xsort.begin(), xsort.end());
	std::sort(ysort.begin(), ysort.end());

	xsort.erase(std::unique(xsort.begin(), xsort.end()), xsort.end());
	ysort.erase(std::unique(ysort.begin(), ysort.end()), ysort.end());

	long long xn = xsort.size();
	long long yn = ysort.size();


	for (int i = 0; i < xn;i++) {
		long long temp = 0;
		for ( int j = 0; j < n; j++) {
			long long len1 = llabs(xpoint[j * 2] - xsort[i])  ;
			long long len2 = llabs(xpoint[j * 2 + 1] - xsort[i]);
			temp = std::max(temp,min(len1, len2));
		}
		xmax = std::min(temp, xmax);
	}
	for (int i = 0; i < yn;i++) {
		long long temp = 0;
		for (int j = 0; j < n; j++) {
			long long len1 = llabs(ypoint[j * 2] - ysort[i]);
			long long len2 = llabs(ypoint[j * 2 + 1] - ysort[i]);
			temp = std::max(temp, min(len1, len2));
		}
		ymax = std::min(temp, ymax);
	}
	
	
	for ( int i = 0; i < xn; i++) {
		for ( int j = i + 1; j < xn; j++) {
			long long temp = 0;
			long long center = (xsort[i] + xsort[j])/2;

			for (register int k = 0; k < n; k++) {
				long long len1 = llabs(xpoint[k * 2] - center);
				long long len2 = llabs(xpoint[k * 2 + 1] - center);
				temp = std::max(temp, min(len1, len2));
			}
			xmax = std::min(temp, xmax);
		}
	}

	
	for (int i = 0; i < yn; i++) {
		for (int j = i + 1; j < yn; j++) {
			long long temp = 0;
			long long center = (ysort[i] + ysort[j]) / 2;

			for (register int k = 0; k < n; k++) {
				long long len1 = llabs(ypoint[k * 2] - center);
				long long len2 = llabs(ypoint[k * 2 + 1] - center);
				temp = std::max(temp, min(len1, len2));
			}
			ymax = std::min(temp, ymax);
		}
	}

	return std::max(xmax, ymax);
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

	 //freopen("input.txt", "r", stdin);

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{

		Answer = 0;
		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
		   Implement your algorithm here.
		   The answer to the case will be stored in variable Answer.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		read();
		Answer = solve();

		// Print the answer to standard output(screen).
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer / 2.0 << endl;
	}

	return 0;//Your program should return 0 on normal termination.
}