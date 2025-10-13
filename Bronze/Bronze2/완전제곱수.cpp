#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> M >> N;

    int square[101];
    for (int i = 1; i <= 100; i++)
        square[i] = i * i;

    int sum = 0, min = -1;
    int low = lower_bound(square + 1, square + 101, M) - square;
    for (int i = low; i <= 100; i++)
    {
        if (square[i] > N)
            break;
        sum += square[i];
        if (min == -1)
            min = square[i];
    }
    if (min == -1)
        cout << -1;
    else
        cout << sum << "\n"
             << min;
}