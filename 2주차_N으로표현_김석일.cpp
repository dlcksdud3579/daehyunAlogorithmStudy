#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<vector<int>> memoization;

bool tryOnNCount(int n, int target, int nCount)
{
    int mult = 1;
    for (int i = 0; i < nCount; i++)
    {
        for (int mem : memoization[nCount - i - 1])
        {
            int added = (n * mult) + mem;
            int subbed = (n * mult) - mem;
            int multied = (n * mult) * mem;

            if (added == target)
                return true;
            if (subbed == target)
                return true;
            if (multied == target)
                return true;

            if (find(memoization[nCount - 1].begin(), memoization[nCount - 1].end(), added) == memoization[nCount - 1].end())
                memoization[nCount].push_back(added);
            if (find(memoization[nCount - 1].begin(), memoization[nCount - 1].end(), subbed) == memoization[nCount - 1].end())
                memoization[nCount].push_back(subbed);
            if (find(memoization[nCount - 1].begin(), memoization[nCount - 1].end(), multied) == memoization[nCount - 1].end())
                memoization[nCount].push_back(multied);

            int reverseDivided = mem / (n * mult);
            if (reverseDivided == target)
                return true;
            if (find(memoization[nCount - 1].begin(), memoization[nCount - 1].end(), reverseDivided) == memoization[nCount - 1].end())
                memoization[nCount].push_back(reverseDivided);

            if (mem == 0)
                continue;

            int divided = (n * mult) / mem;
            if (divided == target)
                return true;
            if (find(memoization[nCount - 1].begin(), memoization[nCount - 1].end(), divided) == memoization[nCount - 1].end())
                memoization[nCount].push_back(divided);
        }
        int simplyMulted = n * mult;
        if (simplyMulted == target)
            return true;
        if (find(memoization[nCount - 1].begin(), memoization[nCount - 1].end(), simplyMulted) == memoization[nCount - 1].end())
            memoization[nCount].push_back(simplyMulted);
        mult = (10 * mult) + mult;
    }
    return false;

}

int solution(int N, int number) {
    memoization.resize(9);
    memoization[1].push_back(N);
    memoization[1].push_back(-N);

    if (N == number)
        return 1;

    for (int i = 2; i <= 8; i++)
    {
        if (tryOnNCount(N, number, i))
            return i;
    }

    return -1;
}

int main()
{
    int n = 5;
    int number = 10;
    cout << solution(n, number) << endl;
}