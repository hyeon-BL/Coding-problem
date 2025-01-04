#include <iostream>
using namespace std;

int divide_by_10(int a, int b)
{
    if (b == 0)
        return 1;
    if (b == 1)
        return a % 10;
    if (b % 2 == 0)
    {
        int temp = divide_by_10(a, b / 2);
        return (temp * temp) % 10;
    }
    return (a * divide_by_10(a, b - 1)) % 10;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;
        cout << divide_by_10(a, b) << '\n';
    }
}