#include <string>
#include <vector>
#include<iostream>

using namespace std;

int solution(vector<int> left, vector<int> right) {
    int answer = 0;

    int rIndex = 0;
    int lIndex = 0;


    while (left.size() > lIndex  && right.size() > rIndex)
    {
        
        if (left.at(lIndex) > right.at(rIndex))
        {
            answer += right.at(rIndex);
            rIndex++;
        }
        else
        {
            lIndex++;
        }
    }
    return answer;
}
int main()
{
    vector<int> left;
    vector<int> right;
    left.push_back(3);
    left.push_back(2);
    left.push_back(5);

    right.push_back(2);
    right.push_back(4);
    right.push_back(1);

    cout << solution(left, right);
    


}
