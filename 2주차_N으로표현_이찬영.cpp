#include <string>
#include <vector>
#include <map>
#include <iostream>
#include<math.h>

using namespace std;

map<int, int> m;
vector<int>* NList[9];

void insertMap(int key,int value)
{
    m.empty();
    int preValue = m[key];
    if (preValue == 0 || preValue > value)
        m[key] = value;
}
void pushNList(int index,int value)
{
    if(value > -5000  && value<50000 )
        NList[index]->push_back(value);

}


int solution(int N, int number) {
    int answer = -1;
    

    for(int i = 1;i<9;i++)
        NList[i] = new vector<int>();

    pushNList(1, N); //NList[1]->push_back(N);
    insertMap(N, 1); // depth 1�� ���  
    

    for (int i = 2; i <= 8; i++)
    {

        // N...N �� ���
        int NNN = 0;  
        for (int j = 0; j < i; j++)
        {
            NNN += N* pow(10, j);
        }
        pushNList(i, NNN);//NList[i]->push_back(NNN);
       insertMap(NNN, i);
        //~ N...N �� ���

        for (vector<int>::iterator iter = NList[i-1]->begin(); iter != NList[i - 1]->end(); ++iter) {
            int preN = *iter;  // ���� ��� N
            int empty = 0;  //���� �� �ӽ� ���� 
            for (int j = 0; i + j <= 8; j++)
            {
                int emptyN = 0;
                for (int k = 0; k <= j; k++)
                {
                    emptyN += N * pow(10, k);
                }
              
                // *���� 
                empty = preN * emptyN;
                insertMap(empty, i);
                pushNList(i, empty);//NList[i]->push_back(empty);
                // ~ *����

                // /���� 
                empty = preN / emptyN;
                insertMap(empty, i);
                pushNList(i, empty);//NList[i]->push_back(empty);
                // ~ /����

                //  + ���� 
                empty = preN + emptyN;
                insertMap(empty, i);
                pushNList(i, empty);//NList[i]->push_back(empty);
                //  +����

                //  -���� 
                empty = preN - emptyN;
                insertMap(empty, i);
                pushNList(i, empty);//NList[i]->push_back(empty);
                // ~  -����
            }
        }
    }
    
    answer = m[number];
    if (answer == NULL)
        answer = -1;

    return answer;
}

int main()
{
    cout << solution(5, 3025);
}