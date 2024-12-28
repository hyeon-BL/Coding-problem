#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cout << i << ' ';

        if (i % 6 == 0 || i == N)
        {
            cout << "Go!" << ' ';
        }
    }
}