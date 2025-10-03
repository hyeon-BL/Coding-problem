#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, t, m;
    cin >> n >> t >> m;

    int s, e;
    cin >> s >> e;

    vector<vector<vector<pair<int, int>>>> adj(t + 1, vector<vector<pair<int, int>>>(n + 1));
    for (int i = 1; i <= t; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u, v, cost;
            cin >> u >> v >> cost;
            adj[i][u].push_back({v, cost});
            adj[i][v].push_back({u, cost});
        }
    }

    // dp[i][j]: 시간 i까지 고려했을 때, s에서 j로 가는 최단 거리
    vector<vector<int>> dp(t + 1, vector<int>(n + 1, INF));
    dp[0][s] = 0;

    for (int i = 1; i <= t; i++)
    {
        // 1. 시간 i에 간선을 사용하지 않는 경우 (대기)
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = dp[i - 1][j];
        }

        // 2. 시간 i에 간선을 사용하는 경우 (이동)
        for (int u = 0; u < n; u++)
        {
            if (dp[i - 1][u] == INF)
                continue;
            for (auto &edge : adj[i][u])
            {
                int v = edge.first;
                int cost = edge.second;
                if (dp[i - 1][u] + cost < dp[i][v])
                {
                    dp[i][v] = dp[i - 1][u] + cost;
                }
            }
        }
    }

    int min_cost = dp[t][e];

    if (min_cost == INF)
        cout << -1 << "\n";
    else
        cout << min_cost << "\n";
}