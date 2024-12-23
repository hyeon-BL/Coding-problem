#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    // 0/1 knapsack problem
    int N, K;
    cin >> N >> K;
    vector<vector<int>> dp(N + 1, vector<int>(K + 1));
    vector<int> w(N), v(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }

    // dp[i][j] = i번째 물건까지 고려했을 때, 무게 j까지 담을 수 있는 최대 가치
    for (int i = 1; i <= N; i++)
    { // O(NK)
        for (int j = 1; j <= K; j++)
        {
            if (w[i - 1] <= j)
            { // 무게가 남으면
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i - 1]] + v[i - 1]);
            }
            else
            { // 무게 초과
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    cout << dp[N][K];
}