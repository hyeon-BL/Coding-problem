#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int t[6];
    for (int i = 0; i < 3; i++)
    {
        int total_f = 0, total_e = 0, total = 0;
        for (int i = 0; i < 6; i++)
        {
            cin >> t[i];
        }
        for (int i = 0; i < 3; i++)
        {
            total_f += t[i] * pow(60, (2 - i));
            total_e += t[i + 3] * pow(60, (2 - i));
        }
        total = total_e - total_f;
        cout << total / 3600 << ' ' << (total % 3600) / 60 << ' ' << total % 60 << '\n';
    }

    return 0;
}