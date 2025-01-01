#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int r = N;

    for (int i = 1; i <= (2 * N - 1); i++)
    {
        for (int j = 1; j <= (2 * N - 1); j++)
        {
            if (j >= r && j <= (2 * N - r))
            {
                cout << "*";
            }
            else if (j < r)
            {
                cout << " ";
            }
        }
        cout << "\n";
        if (i < N)
        {
            r--;
        }
        else
        {
            r++;
        }
    }
}