#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> v(N, vector<int>(N, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> v[i - 1][j - 1];
        }
    }
    for (int i = N - 2; i >= 0; i--)
    { // bottom-up 방식 dynamic programming
        for (int j = 0; j <= i; j++)
        { // i번째 줄의 j번째 수에 i번째 줄의 j번째 수와 j+1번째 수 중 큰 수와 더함
            v[i][j] += max(v[i + 1][j], v[i + 1][j + 1]);
        }
    }
    cout << v[0][0];
}