#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int people, extent;
    int news[5];
    cin >> people >> extent;
    cin >> news[0] >> news[1] >> news[2] >> news[3] >> news[4];

    for (int i = 0; i < 5; i++)
    {
        cout << news[i] - people * extent << ' ';
    }
}