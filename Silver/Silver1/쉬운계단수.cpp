#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N; // 수열의 크기

    vector<vector<long long>> dp(N + 1, vector<long long>(10, 0));
    const int MOD = 1e9;

    // 길이가 1인 경우(0은 시작할 수 없음)
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i] = 1;
    }

    // 길이가 2 이상인 경우
    for (int len = 2; len <= N; len++)
    {
        for (int digit = 0; digit <= 9; digit++)
        {
            if (digit > 0)
            { // 0보다 큰 경우
                dp[len][digit] += dp[len - 1][digit - 1];
            }
            if (digit < 9)
            { // 9보다 작은 경우
                dp[len][digit] += dp[len - 1][digit + 1];
            }
            dp[len][digit] %= MOD;
        }
    }

    // 길이가 N인 모든 계단 수의 개수
    long long result = 0;
    for (int digit = 0; digit <= 9; digit++)
    {
        result += dp[N][digit];
        result %= MOD;
    }

    cout << result;
    return 0;
}