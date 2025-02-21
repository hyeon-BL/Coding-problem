#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> map;
vector<vector<bool>> visited; // 중복 방문 방지
int R, C, K;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
int count_paths = 0;

void dfs(int x, int y, int steps)
{
    if (x == 0 && y == C - 1)
    {
        if (steps == K)
        {
            count_paths++;
        }
        return;
    }

    if (steps > K)
    {
        return;
    }

    visited[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && map[nx][ny] == '.')
        {
            dfs(nx, ny, steps + 1);
        }
    }

    visited[x][y] = false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C >> K;
    map.resize(R, vector<char>(C));
    visited.resize(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < C; j++)
        {
            map[i][j] = s[j];
        }
    }

    dfs(R - 1, 0, 1);

    cout << count_paths;
    return 0;
}