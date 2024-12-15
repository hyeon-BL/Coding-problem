#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m; // n: 세로, m: 가로

    vector<vector<int>> graph(n, vector<int>(m));
    pair<int, int> target;
    for (int i = 0; i < n; i++) { // 그래프 생성
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) { // 타겟 위치 저장
                target = {i, j};
            }
        }
    }

    vector<vector<int>> distance(n, vector<int>(m, -1)); // -1로 초기화된 n x m 2차원 벡터 생성
    queue<pair<int, int>> q;
    q.push(target);
    distance[target.first][target.second] = 0;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    while (!q.empty()) { // BFS 탐색
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && graph[nx][ny] != 0 && distance[nx][ny] == -1) {
                distance[nx][ny] = distance[x][y] + 1; // 이동 횟수 저장
                q.push({nx, ny});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (graph[i][j] == 0) { // 모든 벽은 0으로 출력
                cout << 0 << ' ';
                continue;
            }
            cout << distance[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}