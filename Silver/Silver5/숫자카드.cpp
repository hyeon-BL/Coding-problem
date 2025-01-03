#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> &arr, int target) // O(logN)
{
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
        int mid = (start + end) / 2;

        if (arr[mid] == target)
        {
            return 1;
        }
        else if (arr[mid] < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return 0;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> arr(N);

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end()); // NlogN

    int M;
    cin >> M;
    vector<int> verify(M);

    for (int i = 0; i < M; i++)
    {
        cin >> verify[i];
    }

    for (int i = 0; i < M; i++)
    {
        cout << binary_search(arr, verify[i]) << " ";
    }
}