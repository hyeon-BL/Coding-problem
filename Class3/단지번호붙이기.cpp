#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dfs(int x, int y, int N, vector<vector<bool>>& visited, int** graph) {
    if (x < 0 || x >= N || y < 0 || y >= N || graph[x][y] == 0 || visited[x][y]) {
        return 0;
    }
    visited[x][y] = true;
    int size = 1;

    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };

    for (int i = 0; i < 4; i++) {
        size += dfs(x + dx[i], y + dy[i], N, visited, graph); // CC의 크기를 구하는 재귀함수
    }
    return size;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int** graph = new int*[N];
    for (int i = 0; i < N; i++) {
        graph[i] = new int[N];
        string row;
        cin >> row;
        for (int j = 0; j < N; j++) {
            graph[i][j] = row[j] - '0';
        }
    }

    vector<vector<bool>> visited(N, vector<bool>(N, false));
    vector<int> componentSizes; //
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (graph[i][j] == 1 && !visited[i][j]) { // 1이고 방문하지 않은 정점이라면
                int size = 0;
                size = dfs(i, j, N, visited, graph); // 탐색
                componentSizes.push_back(size);
            }
        }
    }

    sort(componentSizes.begin(), componentSizes.end());
    cout << componentSizes.size() << '\n'; // 총 CC 집합의 개수
    for (int size : componentSizes) {
        cout << size << '\n'; // 각 CC의 크기
    }

    for (int i = 0; i < N; i++) {
        delete[] graph[i];
    }
    delete[] graph;

    return 0;
}