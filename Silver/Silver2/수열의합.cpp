#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, L; // N: 수열의 합, L: 최소 길이
    cin >> N >> L;

    for (int i = L; i <= 100; i++)
    { // 길이가 L 이상 100 이하인 수열
        if ((2 * N - i * i + i) % (2 * i) == 0)
        {                                              // 수열의 합이 N인 수열
            int start = (2 * N - i * i + i) / (2 * i); // 수열의 시작
            if (start < 0)
                continue;
            for (int j = 0; j < i; j++)
            {
                cout << start + j << ' ';
            }
            return 0;
        }
    }

    cout << -1;
}

/*
2*N - i*i + i = 2*i*start

N = start + start + 1 + ... + start + i - 1
  = i*start + i*(i-1)/2
*/