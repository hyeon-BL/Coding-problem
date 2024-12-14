#include<iostream>
#include <queue>
#include <vector>
using namespace std;

struct Point { 
    int x, y, dist;
};

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool isValid(int x, int y, int N, int M, vector<vector<bool>>& visited, int** graph) {
    return (x >= 0 && x < N && y >= 0 && y < M && graph[x][y] == 1 && !visited[x][y]);
}

int bfs(int** graph, int N, int M) {
    queue<Point> q;
    vector<vector<bool>> visited(N, vector<bool>(M, false)); // 2D vector of size N x M
    q.push({0, 0, 1});
    visited[0][0] = true;

    while (!q.empty()) {
        Point p = q.front();
        q.pop();

        if (p.x == N - 1 && p.y == M - 1) {
            return p.dist;
        }

        for (int i = 0; i < 4; i++) {
            int nx = p.x + dx[i];
            int ny = p.y + dy[i];

            if (isValid(nx, ny, N, M, visited, graph)) {
                visited[nx][ny] = true;
                q.push({nx, ny, p.dist + 1});
            }
        }
    }
    return -1; // If there is no path
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    int** graph = new int*[N];
    for (int i = 0; i < N; i++) {
        graph[i] = new int[M];
        string row;
        cin >> row;
        for (int j = 0; j < M; j++) {
            graph[i][j] = row[j] - '0';
        }
    }

    int result = bfs(graph, N, M);
    cout << result;

    for (int i = 0; i < N; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}