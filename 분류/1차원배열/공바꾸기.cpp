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

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        int temp = arr[a];
        arr[a] = arr[b];
        arr[b] = temp;
    }

    for (int i = 1; i <= N; i++)
    {
        cout << arr[i] << " ";
    }
}