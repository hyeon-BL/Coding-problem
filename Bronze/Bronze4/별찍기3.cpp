#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    N++;
    while (N--)
    {
        for (int i = 0; i < N; ++i)
        {
            cout << "*";
        }
        cout << '\n';
    }
}