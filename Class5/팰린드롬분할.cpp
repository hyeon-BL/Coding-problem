#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.length();

    // isPalindrome[i][j]: s[i..j]가 팰린드롬인지 여부
    vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

    // 길이 1인 팰린드롬
    for (int i = 0; i < n; i++)
    {
        isPalindrome[i][i] = true;
    }

    // 길이 2 이상인 팰린드롬
    for (int len = 2; len <= n; len++)
    {
        for (int start = 0; start <= n - len; start++)
        {
            int end = start + len - 1;
            if (len == 2)
            { // 길이가 2인 팰린드롬
                isPalindrome[start][end] = (s[start] == s[end]);
            }
            else
            { // 양 끝 문자가 같고 그 사이 문자열이 팰린드롬이면 팰린드롬
                isPalindrome[start][end] = (s[start] == s[end] && isPalindrome[start + 1][end - 1]);
            }
        }
    }

    // dp[i]: s[0..i]까지의 최소 분할 개수
    vector<int> dp(n);
    for (int i = 0; i < n; i++)
    {
        if (isPalindrome[0][i])
        { // 0부터 i까지 팰린드롬이면 1개로 분할 가능
            dp[i] = 1;
        }
        else
        { // 팰린드롬이 아니면 최소 분할 개수 찾기
            dp[i] = i + 1;
            for (int j = 0; j < i; j++)
            { // 0부터 j까지 팰린드롬이고 j+1부터 i까지 팰린드롬이면 dp[i] 갱신
                if (isPalindrome[j + 1][i])
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }

    cout << dp[n - 1];
    return 0;
}