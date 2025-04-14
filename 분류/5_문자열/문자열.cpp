#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        cout << s[0] << s[s.size() - 1] << '\n';
    }
}