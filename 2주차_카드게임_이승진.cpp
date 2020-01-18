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

	//���ʸ� �����ų� �� �� ���� ��� �߰� ���� ����
	currentValue = MaxValue(Calculate(lIdx + 1, rIdx), Calculate(lIdx + 1, rIdx + 1));

	//������ �� Ŭ �� �����ʸ� ���� ��� ���� ȹ��
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