#include <iostream>
using namespace std;

int cnt;

int recursion(const string &S, int l, int r)
{
    if (l >= r)
    {
        return 1;
    }
    else if (S[l] != S[r])
    {
        return 0;
    }
    cnt++;
    return recursion(S, l + 1, r - 1);
}

int isPalindrome(const string &S)
{
    cnt++;
    return recursion(S, 0, S.size() - 1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        string S;
        cin >> S;

        cnt = 0;
        int result = isPalindrome(S);
        cout << result << ' ' << cnt << '\n';
    }
}