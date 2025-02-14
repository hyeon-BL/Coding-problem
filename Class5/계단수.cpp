#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N; // 수열의 크기

    // dp[len][digit][mask]: 길이가 len이고 끝자리가 digit이며 mask 상태인 계단 수의 개수
    vector<vector<vector<long long>>> dp(N + 1, vector<vector<long long>>(10, vector<long long>(1 << 10, 0)));

    // 길이가 1인 경우(0은 시작할 수 없음)
    for (int i = 1; i <= 9; i++)
    {
        dp[1][i][1 << i] = 1;
    }

    // 길이가 2 이상인 경우
    for (int len = 2; len <= N; len++)
    {
        for (int digit = 0; digit <= 9; digit++)
        {
            for (int mask = 0; mask < (1 << 10); mask++)
            {
                if (digit > 0)
                { // digit보다 1 작은 수를 끝자리로 가지는 계단 수(mask에 digit 추가)
                    dp[len][digit][mask | (1 << digit)] += dp[len - 1][digit - 1][mask];
                    dp[len][digit][mask | (1 << digit)] %= MOD;
                }
                if (digit < 9)
                { // digit보다 1 큰 수를 끝자리로 가지는 계단 수(mask에 digit 추가)
                    dp[len][digit][mask | (1 << digit)] += dp[len - 1][digit + 1][mask];
                    dp[len][digit][mask | (1 << digit)] %= MOD;
                }
            }
        }
    }

    // 길이가 N인 모든 계단 수의 개수(0 ~ 9까지의 모든 수 포함)
    long long result = 0;
    int fullMask = (1 << 10) - 1; // 0부터 9까지 모든 수가 포함된 상태(10진수로 1023)
    for (int digit = 0; digit <= 9; digit++)
    {
        result += dp[N][digit][fullMask];
        result %= MOD;
    }

    cout << result;
    return 0;
}