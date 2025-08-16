#include <iostream>
#include <vector>
#include <climits>
#include <queue>
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
        {
            continue;
        }

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

    return dist;
}

int shortest_cycle(int n, const vector<vector<pair<int, int>>> &graph)
{
    int min_cycle_length = INT_MAX;

    vector<vector<int>> all_distances(n + 1);
    for (int i = 1; i <= n; i++)
    {
        vector<int> dist = dijkstra(i, n, graph);
        all_distances[i] = dist;
    }

    for (int u = 1; u <= n; u++)
    {
        for (const auto &edge : graph[u])
        {
            int v = edge.first;
            int w = edge.second;
            if (all_distances[v][u] != INT_MAX)
            {
                min_cycle_length = min(min_cycle_length, all_distances[u][v] + all_distances[v][u]);
            }
        }
    }

    return min_cycle_length == INT_MAX ? -1 : min_cycle_length;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int result = shortest_cycle(V, graph);
    cout << result << "\n";
}

/*
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int floyd_warshall(int n, const vector<vector<pair<int, int>>> &graph) {
    // Initialize distance matrix
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));

    for (int u = 1; u <= n; u++) {
        for (const auto &edge : graph[u]) {
            int v = edge.first;
            int w = edge.second;
            dist[u][v] = w; // Direct edge weight
        }
    }

    // Floyd-Warshall algorithm
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // Find the shortest cycle
    int min_cycle_length = INT_MAX;
    for (int i = 1; i <= n; i++) {
        if (dist[i][i] != INT_MAX) {
            min_cycle_length = min(min_cycle_length, dist[i][i]);
        }
    }

    return min_cycle_length == INT_MAX ? -1 : min_cycle_length;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int V, E;
    cin >> V >> E;

    vector<vector<pair<int, int>>> graph(V + 1);
    for (int i = 0; i < E; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    int result = floyd_warshall(V, graph);
    cout << result << "\n";

    return 0;
}

*/