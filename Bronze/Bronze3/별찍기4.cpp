#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        for (int j = N; j >= 1; j--)
        {
            if (j <= N - i)
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << "\n";
    }
}