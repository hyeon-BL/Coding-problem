#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> D(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> D[i][j];
        }
    }

    // DP 초기화
    vector<int> dp(1 << N, INT_MAX);
    dp[0] = 0;

    // 모든 상태에 대해 반복
    for (int mask = 0; mask < (1 << N); mask++)
    {
        // Count of assigned tasks (number of set bits in mask)
        int x = 0;
        int temp = mask;
        while (temp)
        {
            x += temp & 1;
            temp >>= 1;
        }
        for (int j = 0; j < N; j++)
        {
            if (!(mask & (1 << j))) // If task j is not assigned
            {
                dp[mask | (1 << j)] = min(dp[mask | (1 << j)], dp[mask] + D[x][j]);
            }
        }
    }

    // 모든 작업이 할당된 상태의 최소 비용 출력
    cout << dp[(1 << N) - 1];
}