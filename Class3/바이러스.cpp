#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    for (int i = 0; i < adj[node].size(); ++i) {
        int next = adj[node][i];
        if (!visited[next]) {
            dfs(next, adj, visited);
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> adj(N + 1);
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1, adj, visited); // Start from the initially infected computer(1)

    int infectedCount = -1; // Exclude the initially infected computer
    for (int i = 1; i <= N; ++i) {
        if (visited[i]) {
            infectedCount++;
        }
    }

    cout << infectedCount << endl;
    return 0;
}