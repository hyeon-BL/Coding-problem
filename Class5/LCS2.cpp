#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s1, s2;
    cin >> s1 >> s2;
    int dp[50][50] = {
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

    // find LCS
    int i = s1.size();
    int j = s2.size();
    string lcs = "";
    while (i > 0 && j > 0)
    {
        if (dp[i][j] == dp[i - 1][j])
        { // 위로 올라갔을 때 값이 같으면 위로
            i--;
        }
        else if (dp[i][j] == dp[i][j - 1])
        { // 왼쪽으로 갔을 때 값이 같으면 왼쪽으로
            j--;
        }
        else
        { // 그 외 대각선으로 이동
            lcs = s1[i - 1] + lcs;
            i--;
            j--;
        }
    }
    cout << '\n'
         << lcs;
}