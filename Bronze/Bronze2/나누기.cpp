#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, F;
    cin >> N >> F;

    int quotient = N / F, remainder = N % F;
    if (remainder == 0)
        cout << "00";
    else
    {
        int result = (quotient * F) / 10;
        if (result < 10)
            cout << "0" << result;
        else
            cout << result;
    }
}