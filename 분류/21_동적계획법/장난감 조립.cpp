#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);
    vector<int> indegree(N + 1, 0);
    for (int i = 0; i < M; i++)
    {
        int X, Y, K;
        cin >> X >> Y >> K;
        adj[Y].push_back({X, K}); // X를 만들기 위해서는 Y가 K개 필요하다. 즉, Y는 X의 선행 조건 (Y -> X)
        indegree[X]++;
    }

    vector<vector<int>> dp(N + 1, vector<int>(N + 1, 0)); // dp[i][j]: j 부품이 i 부품을 만드는데 몇 개 필요한지
    queue<int> q;
    vector<bool> isBasic(N + 1, false);

    for (int i = 1; i <= N; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
            dp[i][i] = 1;
            isBasic[i] = true;
        }
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (auto &edge : adj[cur])
        {
            int next = edge.first;
            int amount = edge.second;

            for (int i = 1; i <= N; i++)
            {
                if (dp[cur][i] > 0)
                { // X 부품의 개수 = Y 부품의 개수 * K
                    dp[next][i] += dp[cur][i] * amount;
                }
            }

            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (isBasic[i])
        {
            cout << i << " " << dp[N][i] << '\n';
        }
    }
}