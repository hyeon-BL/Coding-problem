#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m; // n: 정점의 개수, m: 간선의 개수

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; i++) { // 그래프 생성
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(n + 1, false);
    int connectedComponents = 0;

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            connectedComponents++;
        }
    }

    cout << connectedComponents;
}