#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    int amount;

    cin >> T;
    while (T--)
    {
        cin >> amount;
        cout << amount / 25 << " " << (amount % 25) / 10 << " " << (amount % 25 % 10) / 5 << " " << (amount % 25 % 10 % 5) << "\n";
    }
}