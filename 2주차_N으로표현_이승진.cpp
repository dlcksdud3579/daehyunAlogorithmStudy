#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int OVER_VALUE = 9;
int answer = OVER_VALUE;

int MinValue(int num1, int num2) {
	if (num1 < num2)
		return num1;
	else
		return num2;
}

void Calculate(const int N, const int number, int nCount, const int currentValue) {
	if (nCount >= OVER_VALUE)
		return;

	if (currentValue == number) {
		answer = MinValue(answer, nCount);
		return;
	}

	int calculateValue = 0;
	for (int i = 1; i <= OVER_VALUE - nCount; i++) {
		calculateValue = calculateValue * 10 + N;
		int addNCount = nCount + i;
		Calculate(N, number, addNCount, currentValue + calculateValue);
		Calculate(N, number, addNCount, currentValue - calculateValue);
		Calculate(N, number, addNCount, currentValue * calculateValue);
		Calculate(N, number, addNCount, currentValue / calculateValue);
	}
}

int solution(int N, int number) {
	Calculate(N, number, 0, 0);

	if (answer >= OVER_VALUE)
		answer = -1;

	return answer;
}

int main() {
	int N = 0;
	int number = 0;

	cin >> N;
	cin >> number;

	answer = solution(N, number);
	cout << answer;

	return 0;
}