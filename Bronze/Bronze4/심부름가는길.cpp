#include <iostream>
using namespace std;
int main()
{
    int s[4];
    int total = 0;
    for (int i = 0; i < 4; i++)
    {
        cin >> s[i];
        total += s[i];
    }

    cout << total / 60 << '\n'
         << total % 60;
    return 0;
}