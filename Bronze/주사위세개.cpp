#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b, c;
    cin >> a >> b >> c;

    if (a == b && b == c)
    { // 세 수가 모두 같은 경우
        cout << 10000 + a * 1000;
    }
    else if (a == b || a == c)
    { // 두 수가 같은 경우
        cout << 1000 + a * 100;
    }
    else if (b == c)
    {
        cout << 1000 + b * 100;
    }
    else
    { // 모두 다른 경우
        cout << max({a, b, c}) * 100;
    }
}