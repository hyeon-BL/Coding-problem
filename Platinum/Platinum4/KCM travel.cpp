#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int to;
    int cost;
    int duration;
    Edge(int to, int cost, int duration) : to(to), cost(cost), duration(duration) {}
};

vector<vector<Edge>> graph;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N, M, K;
        cin >> N >> M >> K;
        graph.assign(N + 1, vector<Edge>());

        for (int i = 0; i < K; ++i)
        {
            int u, v, c, d;
            cin >> u >> v >> c >> d;
            graph[v].emplace_back(u, c, d);
        }

        // DP[node][cost] = 최소 시간
        vector<vector<int>> dp(N + 1, vector<int>(M + 1, 1e9));
        dp[1][0] = 0; // 시작점
        for (int j = 1; j <= M; j++)
        {
            for (int i = 1; i <= N; i++)
            {
                dp[i][j] = dp[i][j - 1]; // 이전 비용에서의 최소 시간
                for (const auto &edge : graph[i])
                {
                    if (j >= edge.cost)
                    {
                        dp[i][j] = min(dp[i][j], dp[edge.to][j - edge.cost] + edge.duration);
                    }
                }
            }
        }
        if (dp[N][M] == 1e9)
            cout << "Poor KCM\n";
        else
            cout << dp[N][M] << "\n";
    }
    return 0;
}