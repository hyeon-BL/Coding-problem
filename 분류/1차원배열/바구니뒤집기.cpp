#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }

    while (M--)
    {
        int i, j;
        cin >> i >> j;
        for (int k = 0; k < (j - i + 1) / 2; k++)
        {
            swap(arr[i + k], arr[j - k]);
        }
    }
    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
    }
}