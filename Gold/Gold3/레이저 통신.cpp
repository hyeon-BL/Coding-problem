#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

const int INF = 1e9;
int W, H;
vector<string> map;
pair<int, int> C1, C2;

// 방향: 0:위, 1:오른쪽, 2:아래, 3:왼쪽
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int solve()
{
    vector<vector<int>> dist(H, vector<int>(W, -1)); // 거울 개수 저장용 배열
    queue<pair<int, int>> q;

    dist[C1.first][C1.second] = 0; // 시작점 C1의 비용은 0
    q.push(C1);

    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();

        // 4방향으로 레이저를 쏨
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dx[i];
            int nc = c + dy[i];

            // 벽이나 맵 끝에 닿을 때까지 직진
            while (nr >= 0 && nr < H && nc >= 0 && nc < W && map[nr][nc] != '*')
            {
                // 이전에 방문한 적이 없는 칸이라면
                if (dist[nr][nc] == -1)
                {
                    // 거울을 하나 더 사용해서 도달
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
                // 만약 이미 방문한 곳이라도, 더 적은 거울로 도달한 경로가
                // 이미 이 라인을 탐색했을 것이므로 더 진행할 필요가 없음.
                // 하지만 현재 경로와 같은 비용으로 도달했다면 계속 진행해야
                // 그 너머의 미방문 지점을 찾을 수 있으므로 break하지 않음.

                nr += dx[i];
                nc += dy[i];
            }
        }
    }

    return dist[C2.first][C2.second] - 1; // 시작점에서 거울 하나 세운 것 제외
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> W >> H;
    map.resize(H);
    vector<pair<int, int>> C_points;
    for (int i = 0; i < H; ++i)
    {
        cin >> map[i];
        for (int j = 0; j < W; ++j)
        {
            if (map[i][j] == 'C')
            {
                C_points.push_back({i, j});
            }
        }
    }
    C1 = C_points[0];
    C2 = C_points[1];

    cout << solve() << endl;

    return 0;
}