#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int bills[6] = {500, 100, 50, 10, 5, 1};

    int amount, price;
    cin >> amount;

    price = 1000 - amount;

    int count = 0;
    for (int i = 0; i < 6; i++)
    {
        count += price / bills[i];
        price %= bills[i];
    }
    cout << count;
}