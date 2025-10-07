#include <iostream>
#include <cstdlib>
#include <ctime>
#include <set>
using namespace std;

int main()
{
    srand(time(0)); // 랜덤 시드 초기화

    int resp = 0, flag = 0;
    int a = 0, b = 0;
    set<int> asked_A;
    set<int> asked_B;

    for (int question = 1; question <= 19997; question++)
    {
        int var;
        do
        {
            var = rand() % 10000 + 1; // 1부터 10000 사이의 랜덤 값
        } while ((asked_A.count(var) && flag == 0) || (asked_B.count(var) && flag == 1)); // 이미 물어본 값이면 다시 생성

        if (flag == 0)
            asked_A.insert(var);
        else
            asked_B.insert(var);

        cout << "? " << (flag == 0 ? "A " : "B ") << var << endl;

        cin >> resp;

        // 채점기의 답변을 시뮬레이션
        if (resp == 1 && flag == 0)
        {
            a = var;
            flag = 1; // A의 값을 찾았으므로 B를 찾기 시작
        }
        else if (resp == 1 && flag == 1)
        {
            b = var;

            cout << "! " << a + b << endl;
            break;
        }
    }
    return 0;
}