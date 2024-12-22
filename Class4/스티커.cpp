#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, n;
    cin >> T;
    while (T--)
    {
        cin >> n;
        vector<vector<int>> v(2, vector<int>(n));
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> v[i][j];
            }
        }
        vector<vector<int>> dp(2, vector<int>(n));
        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        dp[0][1] = dp[1][0] + v[0][1];
        dp[1][1] = dp[0][0] + v[1][1];
        for (int i = 2; i < n; i++)
        {
            dp[0][i] = max(dp[1][i - 1], dp[1][i - 2]) + v[0][i];
            dp[1][i] = max(dp[0][i - 1], dp[0][i - 2]) + v[1][i];
            // 다른 행의 i-1번째와 i-2번째 중 큰 값을 더해준다.
        }
        cout << max(dp[0][n - 1], dp[1][n - 1]) << '\n';
    }
}