#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<pair<int, int>> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    int square[101][101] = {0};
    for (int i = 0; i < N; i++)
    {
        for (int j = arr[i].first; j < arr[i].first + 10; j++)
        {
            for (int k = arr[i].second; k < arr[i].second + 10; k++)
            {
                square[j][k] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < 101; i++)
    {
        for (int j = 0; j < 101; j++)
        {
            if (square[i][j] == 1)
            {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}