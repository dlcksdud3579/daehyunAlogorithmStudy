#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<math.h>

using namespace std;

map<int, int> m;

void insertMap(int key,int value)
{
    m.empty();
    int preValue = m[key];
    if (preValue == 0 || preValue > value)
        m[key] = value;
}




int solution(int N, int number) {
    int answer = -1;
    vector<int> *NList[9];

    for(int i = 1;i<9;i++)
        NList[i] = new vector<int>();

    NList[1]->push_back(N);
    insertMap(N, 1); // depth 1�� ���  
    

    for (int i = 2; i <= 8; i++)
    {

        // N...N �� ���
        int NNN = 0;  
        for (int j = 0; j < i; j++)
        {
            NNN += N* pow(10, j);
        }
        NList[i]->push_back(NNN);
       insertMap(NNN, i);
        //~ N...N �� ���

        for (vector<int>::iterator iter = NList[i-1]->begin(); iter != NList[i - 1]->end(); ++iter) {
            int preN = *iter;  // ���� ��� N
            int empty = 0;  //���� �� �ӽ� ���� 

            // *���� 
            empty = preN * N;
            insertMap(empty, i);
            NList[i]->push_back(empty);
            // ~ *����

            // /���� 
            empty = preN / N;
            insertMap(empty, i);
            NList[i]->push_back(empty);
            // ~ /����

            //  + ���� 
            empty = preN + N;
            insertMap(empty, i);
            NList[i]->push_back(empty);
            //  +����

            //  -���� 
            empty = preN - N;
            insertMap(empty, i);
            NList[i]->push_back(empty);
            // ~  -����
        }
    }
    
    answer = m[number];
    if (answer == NULL)
        answer = -1;

    return answer;
}

int main()
{
    solution(5, 12);
}