#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int solution(vector<int> left, vector<int> right) {
	int answer = 0;
	left.push_back(0);
	right.push_back(0);
	vector<vector<int>> memoization(left.size(), vector<int>(left.size(), -1));
	memoization[0][0] = 0;
	int size = left.size();

	for (int flip = 1; flip < size * 2; flip++)
	{
		for (int l = 0; l <= flip; l++)
		{
			int r = flip - l;
			if (r >= size || l >= size)
				continue;
			int maxPoint = 0;
			if (l - 1 >= 0)
				maxPoint = max(maxPoint, memoization[l - 1][r]);
			if (r - 1 >= 0 && left[l] > right[r - 1])
				maxPoint = max(maxPoint, memoization[l][r - 1] + right[r - 1]);
			if (l - 1 >= 0 && r - 1 >= 0)
				maxPoint = max(maxPoint, memoization[l - 1][r - 1]);
			memoization[l][r] = maxPoint;
		}
		//showMatrix(memoization);
	}
	answer = memoization[size - 1][size - 1];



	return answer;
}