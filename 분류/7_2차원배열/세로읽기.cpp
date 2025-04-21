#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    char arr[5][15] = {' '};
    for (int i = 0; i < 5; i++)
    {
        string s;
        getline(cin, s);
        for (int j = 0; j < s.length(); j++)
        {
            arr[i][j] = s[j];
        }
    }

    for (int j = 0; j < 15; j++)
    {
        for (int i = 0; i < 5; i++)
        {
            if (arr[i][j] != ' ' && arr[i][j] != '\0')
            { // 문자열이 없어나 end에 도달하지 않았을 때
                cout << arr[i][j];
            }
        }
    }
}