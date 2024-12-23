#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;
    int dp[1001][1001] = {
        0,
    };
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            if (s1[i - 1] == s2[j - 1])
            { // 같으면 대각선 위의 값 + 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            { // 다르면 위나 왼쪽 중 큰 값
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1.size()][s2.size()];
}