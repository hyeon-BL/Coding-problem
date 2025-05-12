#include <iostream>
#include <vector>
using namespace std;

#define mod 10007

/*
    dp[i][j] : S[i] ~ S[j]까지 구간의 팰린드롬 개수
    dp[i][j] = dp[i+1][j-1] + 1 (S[i] == S[j])
    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1] (S[i] != S[j])
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string S; // 입력받을 문자열
    cin >> S;
    int N = S.size();                                         // 문자열의 길이
    vector<vector<long long>> dp(N, vector<long long>(N, 0)); // dp[i][j] : S[i] ~ S[j]까지 구간의 팰린드롬 개수
    long long count = 0;                                      // 팰린드롬의 개수
    for (int i = 0; i < N; i++)
    { // 길이가 1인 문자열은 무조건 팰린드롬
        dp[i][i] = 1;
    }
    for (int i = 1; i < N; i++)
    { // 길이가 2인 문자열은 양쪽 끝이 같으면 팰린드롬
        dp[i - 1][i] = 2;
        if (S[i - 1] == S[i])
        {
            dp[i - 1][i] += 1;
        }
    }
    for (int i = 2; i < N; i++)
    { // 길이가 3 이상인 문자열은 양쪽 끝이 같고 가운데가 팰린드롬이면 팰린드롬
        for (int j = i; j < N; j++)
        {
            if (S[j - i] == S[j])
            {
                dp[j - i][j] = (dp[j - i + 1][j] + dp[j - i][j - 1] + 1) % mod;
            }
            else
            {
                dp[j - i][j] = (mod + dp[j - i][j - 1] + dp[j - i + 1][j] - dp[j - i + 1][j - 1]) % mod;
            }
        }
    }

    count = dp[0][N - 1]; // dp[0][N-1]에 팰린드롬의 개수가 저장되어 있음
    cout << count;
    return 0;
}