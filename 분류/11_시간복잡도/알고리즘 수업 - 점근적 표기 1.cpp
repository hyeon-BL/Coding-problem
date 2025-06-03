#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a1, a0, c, n;
    cin >> a1 >> a0 >> c >> n;

    if (a1 * n + a0 <= c * n && a1 <= c)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << 0 << '\n';
    }
}