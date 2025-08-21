#include <iostream>
#include <vector>
using namespace std;

int M, N;
vector<vector<int>> dp;
vector<vector<int>> map;
int move_x[] = {0, 0, -1, 1};
int move_y[] = {-1, 1, 0, 0};

int dfs(int x, int y)
{ // recursive하게 (M, N)부터 경로 역추적
    if (x == M && y == N)
    {
        return 1; // 도착 지점에 도달
    }

    if (dp[x][y] != -1)
    {
        return dp[x][y]; // 계산 완료된 지점
    }

    dp[x][y] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + move_x[i];
        int ny = y + move_y[i];
        if (nx >= 1 && nx <= M && ny >= 1 && ny <= N && map[nx][ny] < map[x][y])
        {
            dp[x][y] += dfs(nx, ny);
        }
    }
    return dp[x][y];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> M >> N;

    map.resize(M + 1, vector<int>(N + 1, 0));
    dp.resize(M + 1, vector<int>(N + 1, -1));

    for (int i = 1; i <= M; i++)
        for (int j = 1; j <= N; j++)
            cin >> map[i][j];

    cout << dfs(1, 1); // (1, 1)에서 (M, N)으로 가는 경로의 수
    return 0;
}