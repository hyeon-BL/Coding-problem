#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    char chess[8][8];
    int cnt = 0;

    for (int i = 0; i < 8; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 8; j++)
        {
            chess[i][j] = s[j];
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0 && chess[i][j] == 'F')
            {
                cnt++;
            }
        }
    }

    cout << cnt;
}