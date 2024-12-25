#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    string str, result = "";
    char prev = ' ';
    while (N--)
    {
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] != prev)
            {
                result += str[i];
                prev = str[i];
            }
        }
        cout << result << '\n';
        result = "";
        prev = ' ';
    }
}