#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long N, storage, result = 0;
    cin >> N;

    int *arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    cin >> storage;

    for (int i = 0; i < N; i++)
    {
        if (arr[i] > 0)
        {
            result += (arr[i] + storage - 1) / storage; // Calculate the number of storage units needed
        }
    }

    cout << result * storage;
    delete[] arr;
    return 0;
}