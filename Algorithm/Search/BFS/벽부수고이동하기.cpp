#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct State
{ // State of BFS
    int x, y, dist, wall_broken;
};

int bfs(int N, int M)
{
    queue<State> q;
    vector<vector<vector<bool>>> visited(N, vector<vector<bool>>(M, vector<bool>(2, false)));
    q.push({0, 0, 1, 0});
    visited[0][0][0] = true;

    while (!q.empty())
    {
        State curr = q.front(); // 현재 상태(x, y, 이동거리, 벽 부순 여부)
        q.pop();

        // 목적지 도착
        if (curr.x == N - 1 && curr.y == M - 1)
        {
            return curr.dist;
        }

        // 상하좌우 이동
        for (auto &dir : directions)
        {
            int nx = curr.x + dir.first;
            int ny = curr.y + dir.second;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M)
            {
                if (graph[nx][ny] == 0 && !visited[nx][ny][curr.wall_broken])
                {
                    // 방문한 적이 없고, 벽을 부순 적이 없다면
                    visited[nx][ny][curr.wall_broken] = true;
                    q.push({nx, ny, curr.dist + 1, curr.wall_broken});
                }
                else if (graph[nx][ny] == 1 && curr.wall_broken == 0 && !visited[nx][ny][1])
                {
                    // 벽을 부순 적이 없고, 벽이 있다면
                    visited[nx][ny][1] = true;
                    q.push({nx, ny, curr.dist + 1, 1});
                }
            }
        }
    }

    return -1; // No path found
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    graph.resize(N, vector<int>(M));

    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            graph[i][j] = row[j] - '0';
        }
    }

    int result = bfs(N, M);
    cout << result;

    return 0;
}