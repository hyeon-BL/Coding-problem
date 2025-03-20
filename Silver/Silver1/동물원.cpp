#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> dp(N + 1, vector<int>(3, 0));
    const int MOD = 9901;

    // Base case
    dp[1][0] = 1; // 사자가 없는 경우
    dp[1][1] = 1; // 왼쪽 우리에 사자가 있는 경우
    dp[1][2] = 1; // 오른쪽 우리에 사자가 있는 경우

    // DP
    for (int i = 2; i <= N; ++i)
    {
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
    }

    // Result
    int result = (dp[N][0] + dp[N][1] + dp[N][2]) % MOD;
    cout << result;
}