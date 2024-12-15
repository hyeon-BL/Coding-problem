#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n; // n: 정점의 개수

    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++) { // 그래프 생성(adjacency matrix)
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    vector<vector<int>> reachable(n, vector<int>(n, 0)); // 0으로 초기화된 n x n 2차원 벡터 생성

    for (int i = 0; i < n; i++) {
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(i); // 시작 정점 i부터 BFS 탐색

        while (!q.empty()) {
            int curr = q.front(); // 큐의 맨 앞 정점을 꺼냄
            q.pop();

            for (int j = 0; j < n; j++) {
                if (graph[curr][j] == 1 && !visited[j]) { // curr 정점에서 j 정점으로 갈 수 있는 경우
                    visited[j] = true;
                    reachable[i][j] = 1;
                    q.push(j);
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << reachable[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}