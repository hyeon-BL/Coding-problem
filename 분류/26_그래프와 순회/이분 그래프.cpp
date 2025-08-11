#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int K;
    cin >> K;
    while (K--)
    {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V + 1);
        for (int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V + 1, -1);
        bool isBipartite = true;

        for (int start = 1; start <= V; start++)
        { // 모든 정점에 대해 BFS 수행
            if (color[start] == -1)
            {
                queue<int> q;
                q.push(start);
                color[start] = 0; // 시작 정점에 색상 0 할당

                while (!q.empty())
                {
                    int curr = q.front();
                    q.pop();

                    for (int neighbor : adj[curr])
                    {
                        if (color[neighbor] == -1)
                        { // 색상이 할당되지 않은 경우 다른 색상 할당
                            color[neighbor] = 1 - color[curr];
                            q.push(neighbor);
                        }
                        else if (color[neighbor] == color[curr])
                        { // 인접한 정점과 색상이 같은 경우 이분 그래프가 아님
                            isBipartite = false;
                            break;
                        }
                    }
                }
            }
        }

        cout << (isBipartite ? "YES" : "NO") << "\n";
    }
}