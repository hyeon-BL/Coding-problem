#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

struct Shark
{
    int x, y, size = 2, eat = 0;
};

int bfs(Shark &s, int N)
{
    vector<vector<int>> visited(N, vector<int>(N, -1));
    queue<pair<int, int>> q;
    q.push({s.x, s.y});
    visited[s.x][s.y] = 0;
    int time = 0;

    while (!q.empty())
    {
        int qsize = q.size();
        vector<pair<int, int>> fish;

        while (qsize--)
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (auto &dir : directions)
            {
                int nx = x + dir.first;
                int ny = y + dir.second;

                if (nx >= 0 && nx < N && ny >= 0 && ny < N && visited[nx][ny] == -1)
                {
                    if (graph[nx][ny] == 0 || graph[nx][ny] == s.size)
                    { // 빈칸이거나 상어 크기와 같은 물고기
                        visited[nx][ny] = visited[x][y] + 1;
                        q.push({nx, ny});
                    }
                    else if (graph[nx][ny] < s.size)
                    { // 먹을 수 있는 물고기
                        visited[nx][ny] = visited[x][y] + 1;
                        fish.push_back({nx, ny});
                    }
                }
            }
        }

        if (!fish.empty())
        {
            sort(fish.begin(), fish.end()); // 가장 위, 왼쪽에 있는 물고기부터 먹기
            pair<int, int> target = fish[0];

            time += visited[target.first][target.second];

            s.x = target.first;
            s.y = target.second;

            graph[target.first][target.second] = 0;
            s.eat++;
            if (s.eat == s.size)
            { // 상어 크기만큼 물고기를 먹었을 때
                s.size++;
                s.eat = 0;
            }

            visited.assign(N, vector<int>(N, -1));
            while (!q.empty())
                q.pop();
            q.push({s.x, s.y});
            visited[s.x][s.y] = 0;
        }
    }

    return time;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    graph.assign(N, vector<int>(N, 0));
    Shark s;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> graph[i][j];
            if (graph[i][j] == 9)
            {
                s.x = i;
                s.y = j;
                graph[i][j] = 0; // 상어 위치 빈칸으로
            }
        }
    }

    cout << bfs(s, N);

    return 0;
}