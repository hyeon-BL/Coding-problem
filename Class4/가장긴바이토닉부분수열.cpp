#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> arr(N);
    vector<int> dp_inc(N, 1); // increasing from left
    vector<int> dp_dec(N, 1); // decreasing from right

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    // Find LIS from left to right
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j]) // strictly increasing
            {
                dp_inc[i] = max(dp_inc[i], dp_inc[j] + 1);
            }
        }
    }

    // Find LIS from right to left (equivalent to LDS)
    for (int i = N - 1; i >= 0; i--)
    {
        for (int j = N - 1; j > i; j--)
        {
            if (arr[i] > arr[j]) // strictly decreasing
            {
                dp_dec[i] = max(dp_dec[i], dp_dec[j] + 1);
            }
        }
    }

    // Find the maximum bitonic sequence length
    int max_length = 0;
    for (int i = 0; i < N; i++)
    {
        max_length = max(max_length, dp_inc[i] + dp_dec[i] - 1);
    }

    cout << max_length;
    return 0;
}