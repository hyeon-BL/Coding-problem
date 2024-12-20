#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> cost(N, vector<int>(3));
    for (int i = 0; i < N; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    vector<vector<int>> dp(N, vector<int>(3));
    dp[0][0] = cost[0][0]; // 0번째 집을 R로 칠할 때의 비용
    dp[0][1] = cost[0][1]; // 0번째 집을 G로 칠할 때의 비용
    dp[0][2] = cost[0][2]; // 0번째 집을 B로 칠할 때의 비용

    for (int i = 1; i < N; i++)
    {
        dp[i][0] = cost[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = cost[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = cost[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    int result = min({dp[N - 1][0], dp[N - 1][1], dp[N - 1][2]});
    cout << result;

    return 0;
}