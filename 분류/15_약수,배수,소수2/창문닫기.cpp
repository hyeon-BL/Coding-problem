#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N개의 창문 및 사람
    cin >> N;

    for (int i = 1; i <= 46340; i++)
    { // 46340^2 = 2147395600, 46341^2 = 2147488281
        if (i * i > N)
        {
            cout << i - 1 << "\n"; // i-1이 N보다 작거나 같은 최대 정수
            break;
        }
    }
}

/*
N : 창문 상태
1 : 1
2 : 10
3 : 100
4 : 1001
5 : 10010
6 : 100100
7 : 1001000
8 : 10010000
9 : 100100001
*/