#include <iostream>
#include <vector>
using namespace std;

/*
비트마스킹
1001001 -> 1, 4, 7번째 수열의 수를 더함

*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, S; // N: 수열의 길이, S: 합
    cin >> N >> S;
    vector<int> sequence(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }

    int cnt = 0;
    for (int i = 1; i < (1 << N); i++)
    { // 1부터 2^N-1까지 -> 모든 부분 수열에 대하여
        int sum = 0;
        for (int j = 0; j < N; j++)
        {
            if (i & (1 << j))
            { // i의 j번째 비트가 1이면
                sum += sequence[j];
            }
        }
        if (sum == S)
        {
            cnt++;
        }
    }

    cout << cnt;
}