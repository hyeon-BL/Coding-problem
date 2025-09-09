#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, const vector<vector<int>>& graph, const vector<int>& villages, vector<vector<int>>& dp, vector<bool>& visited) {
    visited[node] = true;
    dp[node][1] = villages[node]; // node가 우수마을일 때

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, villages, dp, visited);
            dp[node][0] += max(dp[neighbor][0], dp[neighbor][1]); // node가 우수마을이 아닐 때
            dp[node][1] += dp[neighbor][0]; // node가 우수마을일 때
        }
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> villages(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        cin >> villages[i];
    }
    vector<vector<int>> graph(N + 1);
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> dp(N + 1, vector<int>(2, 0)); // dp[i][0]: i가 우수마을이 아닐 때, dp[i][1]: i가 우수마을일 때
    vector<bool> visited(N + 1, false);

    dfs(1, graph, villages, dp, visited);
    cout << max(dp[1][0], dp[1][1]) << "\n";

    return 0;
}