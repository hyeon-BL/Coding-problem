#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// 단지번호붙이기 문제 참고(int->char)
// Graph 탐색 문제
int dfs(int x, int y, int N, vector<vector<bool>>& visited, vector<vector<char>>& graph) {
    if (x < 0 || x >= N || y < 0 || y >= N || visited[x][y]) {
        return 0;
    }
    visited[x][y] = true;
    int size = 1;

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++) {
        if (x + dx[i] < 0 || x + dx[i] >= N || y + dy[i] < 0 || y + dy[i] >= N) {
            continue;
        }

        if (graph[x][y] == graph[x + dx[i]][y + dy[i]]) {
            size += dfs(x + dx[i], y + dy[i], N, visited, graph);
        }
    }
    return size;
}


void connectedcom(int N, std::vector<std::vector<char>> &graph)
{
    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<int> componentSizes;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                int size = dfs(i, j, N, visited, graph);
                componentSizes.push_back(size);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());
    cout << componentSizes.size() << ' ';
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<char>> graph(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            graph[i][j] = row[j];
        }
    }

    connectedcom(N, graph);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 'G') {
                graph[i][j] = 'R';
            }
        }
    }

    connectedcom(N, graph);

    return 0;
}