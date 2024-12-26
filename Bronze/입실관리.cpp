#include <iostream>
#include <cctype>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while (N--)
    {
        string s;
        cin >> s;
        for (int i = 0; i < s.size(); i++)
        {
            s[i] = tolower(s[i]);
        }
        cout << s << '\n';
    }
}