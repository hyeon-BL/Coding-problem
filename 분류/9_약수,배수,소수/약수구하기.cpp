#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<int> arr;
    for (int i = 1; i <= N; i++)
    {
        if (N % i == 0)
        {
            arr.push_back(i);
        }
    }
    if (arr.size() < K)
    {
        cout << 0;
    }
    else
    {
        cout << arr[K - 1];
    }
}