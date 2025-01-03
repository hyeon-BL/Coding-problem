#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> arr(N);
    vector<int> temp(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    if (N == 0) // N이 0일 경우
    {
        cout << 0;
        return 0;
    }

    sort(arr.begin(), arr.end());

    for (int i = 0; i < N; i++)
    {
        temp[i] = arr[i] * (N - i);
    }
    cout << *max_element(temp.begin(), temp.end());
}