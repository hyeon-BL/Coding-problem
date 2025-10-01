#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define divide 1'000'000'003

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    if (K == 1)
    {
        cout << N << '\n';
        return 0;
    }

    // N개의 색상환 중 K개의 색상을 인접하지 않게 고르는 방법의 수
    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

    // Base cases
    for (int i = 1; i <= N; i++)
    {
        dp[i][0] = 1;
        dp[i][1] = i;
    }

    // DP table 채우기
    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j <= K; j++)
        { // dp[i][j] = dp[i-1][j] + dp[i-2][j-1]
          // i번째 색상을 선택하지 않는 경우 + i번째 색상을 선택하는 경우
            dp[i][j] = (dp[i - 1][j] + dp[i - 2][j - 1]) % divide;
        }
    }

    // circular condition
    // dp[N-1][K] : 1번째 색상을 선택하지 않는 경우
    // dp[N-3][K-1] : 1번째 색상을 선택하는 경우 (2번째, N번째 색상 선택 불가)
    int result = (dp[N - 1][K] + dp[N - 3][K - 1]) % divide;

    cout << result << '\n';
}