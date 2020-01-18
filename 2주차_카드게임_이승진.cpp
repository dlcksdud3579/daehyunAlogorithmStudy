#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> leftVec, rightVec, answerVec;

int AnswerVecIdx(int leftIdx, int rightIdx) {
	return leftIdx * leftVec.size() + rightIdx;
}

int MaxValue(int value1, int value2) {
	if (value1 >= value2)
		return value1;
	return value2;
}

int Calculate(int lIdx, int rIdx) {
	if (lIdx == leftVec.size() || rIdx == rightVec.size())
		return 0;

	int& currentValue = answerVec[AnswerVecIdx(lIdx, rIdx)];
	if (currentValue != -1)
		return currentValue;

	//왼쪽만 버리거나 둘 다 버릴 경우 추가 점수 없음
	currentValue = MaxValue(Calculate(lIdx + 1, rIdx), Calculate(lIdx + 1, rIdx + 1));

	//왼쪽이 더 클 때 오른쪽만 버릴 경우 점수 획득
	if (leftVec[lIdx] > rightVec[rIdx])
		currentValue = MaxValue(currentValue, rightVec[rIdx] + Calculate(lIdx, rIdx + 1));

	return currentValue;
}

int solution(vector<int> left, vector<int> right) {
	leftVec = left;
	rightVec = right;
	answerVec.resize((left.size() + 1) * (right.size() + 1), -1);

	int answer = Calculate(0, 0);
	return answer;
}

int main() {
	vector<int> left = { 3, 2, 5 };
	vector<int> right = { 2, 4, 1 };

	int answer = solution(left, right);
	cout << answer;
}