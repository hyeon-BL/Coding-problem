#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < s.size() - 1; i++)
    {
        if (s[i] == 'c' && (s[i + 1] == '=' || s[i + 1] == '-'))
        {
            cnt++;
        }
        else if (s[i] == 'd' && s[i + 1] == '-')
        {
            cnt++;
        }
        else if (s[i] == 'l' && s[i + 1] == 'j')
        {
            cnt++;
        }
        else if (s[i] == 'n' && s[i + 1] == 'j')
        {
            cnt++;
        }
        else if (s[i] == 's' && s[i + 1] == '=')
        {
            cnt++;
        }
        else if (s[i] == 'z' && s[i + 1] == '=')
        {
            cnt++;
        }
        else if (i < s.size() - 2 && s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=')
        {
            cnt++;
        }
    }
    cout << s.size() - cnt;
}