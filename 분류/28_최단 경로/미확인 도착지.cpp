#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> dijkstra(int start, int n, const vector<vector<pair<int, int>>> &graph)
{
    vector<int> dist(n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    return dist; // Return shortest distances
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--)
    {
        int n, m, t;
        cin >> n >> m >> t;

        int s, g, h;
        cin >> s >> g >> h;

        vector<vector<pair<int, int>>> graph(n + 1);
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            cin >> u >> v >> w;
            graph[u].emplace_back(v, w);
            graph[v].emplace_back(u, w);
        }

        // Compute shortest distances from s, g, and h
        vector<int> dist_from_s = dijkstra(s, n, graph);
        vector<int> dist_from_g = dijkstra(g, n, graph);
        vector<int> dist_from_h = dijkstra(h, n, graph);

        vector<int> destinations;
        for (int i = 0; i < t; i++)
        {
            int dest;
            cin >> dest;
            destinations.push_back(dest);
        }
        sort(destinations.begin(), destinations.end());

        // Check if each destination can be reached through the edge g-h
        for (int dest : destinations)
        {
            int dist_via_g_h = dist_from_s[g] + dist_from_g[h] + dist_from_h[dest];
            int dist_via_h_g = dist_from_s[h] + dist_from_h[g] + dist_from_g[dest];

            if (dist_from_s[dest] == dist_via_g_h || dist_from_s[dest] == dist_via_h_g)
            {
                cout << dest << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}

/*
g, h를 경유하는 최단 경로가 존재하는지 확인
-> 단순히 노드를 지났는지 확인하는 게 아니라 g-h 간선이 포함되어야 함
*/