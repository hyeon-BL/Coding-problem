#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(vector<vector<bool>> &visited, int N, int M)
{
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto &dir : directions)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && graph[nx][ny] == 0)
            { // 공기가 통과 가능한 공간
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    graph.assign(N, vector<int>(M, 0));
    vector<pair<int, int>> cheeses; // 치즈 좌표

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 1)
            {
                cheeses.push_back({i, j});
            }
        }
    }

    int time = 0;
    while (!cheeses.empty())
    { // 치즈가 모두 녹을 때까지
        vector<vector<bool>> visited(N, vector<bool>(M, false));
        bfs(visited, N, M); // 외부 공기 체크

        vector<pair<int, int>> next_cheeses;
        for (auto &cheese : cheeses)
        { // 치즈 녹이기
            int x = cheese.first;
            int y = cheese.second;
            int melted_count = 0;

            for (auto &dir : directions)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // 외부 공기와 접촉한 면의 개수 체크
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && visited[nx][ny])
                {
                    melted_count++;
                }
            }

            if (melted_count >= 2)
            {
                graph[x][y] = 0;
            }
            else
            {
                next_cheeses.push_back(cheese);
            }
        }

        cheeses = next_cheeses;
        time++;
    }

    cout << time;

    return 0;
}