#include <iostream>
using namespace std;
int main()
{
    int total_s = 0, total_t = 0;
    for (int i = 0; i < 4; i++)
    {
        int s;
        cin >> s;
        total_s += s;
    }
    for (int i = 0; i < 4; i++)
    {
        int t;
        cin >> t;
        total_t += t;
    }
    if (total_s >= total_t)
        cout << total_s;
    else
        cout << total_t;

    return 0;
}