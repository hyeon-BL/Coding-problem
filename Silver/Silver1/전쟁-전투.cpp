#include <iostream>
#include <vector>
using namespace std;

vector<vector<char>> war_area;
vector<vector<bool>> visited;
int N, M;

int dfs(int y, int x, char soldier)
{
    if (y < 0 || y >= M || x < 0 || x >= N)
        return 0;
    if (visited[y][x] || war_area[y][x] != soldier)
        return 0;

    visited[y][x] = true;
    int ret = 1;

    ret += dfs(y - 1, x, soldier);
    ret += dfs(y + 1, x, soldier);
    ret += dfs(y, x - 1, soldier);
    ret += dfs(y, x + 1, soldier);

    return ret;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    war_area.resize(M, vector<char>(N));
    visited.resize(M, vector<bool>(N, false));

    for (int i = 0; i < M; i++)
    { // 세로로
        string row;
        cin >> row;
        for (int j = 0; j < N; j++)
        { // 가로로
            war_area[i][j] = row[j];
        }
    }

    int ans = 0;
    int power_of_white = 0, power_of_blue = 0;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                int num_of_soldiers = dfs(i, j, war_area[i][j]);
                if (war_area[i][j] == 'W')
                    power_of_white += num_of_soldiers * num_of_soldiers;
                else
                    power_of_blue += num_of_soldiers * num_of_soldiers;
            }
        }
    }

    cout << power_of_white << " " << power_of_blue;
}