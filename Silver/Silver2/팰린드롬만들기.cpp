#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;
    int n = s.size();
    int min_len = 2 * n;

    for (int i = 0; i < n; i++)
    {
        bool is_palindrome = true;
        for (int j = 0; j < (n - i) / 2; j++)
        { // i ~ i + j & n - 1 - j ~ n - 1 비교 -> 팰린드롬인지 확인
            if (s[i + j] != s[n - 1 - j])
            {
                is_palindrome = false;
                break;
            }
        }
        if (is_palindrome)
        {
            min_len = n + i;
            break;
        }
    }

    cout << min_len;
}