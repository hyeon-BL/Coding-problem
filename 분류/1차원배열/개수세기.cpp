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
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    int v;
    cin >> v;

    int cnt = 0;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == v)
            cnt++;
    }
    cout << cnt;
}