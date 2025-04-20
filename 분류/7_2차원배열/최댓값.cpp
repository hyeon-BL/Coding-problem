#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int arr[10][10] = {0};
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> arr[i][j];
        }
    }

    int max = 0, r = 1, c = 1;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (arr[i][j] > max)
            {
                max = arr[i][j];
                r = i;
                c = j;
            }
        }
    }
    cout << max << '\n'
         << r << ' ' << c;
    return 0;
}