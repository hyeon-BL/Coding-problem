#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<long long> bellman_ford(int start, int n, const vector<vector<pair<long long, long long>>> &graph)
{
    vector<long long> dist(n + 1, INT_MAX);
    dist[start] = 0;

    for (int i = 1; i < n; i++)
    { // Relax edges: n - 1번 반복
        for (int j = 1; j <= n; j++)
        { // Iterate over all vertices
            for (auto &edge : graph[j])
            {
                long long v = edge.first;
                long long w = edge.second;
                if (dist[j] != INT_MAX && dist[j] + w < dist[v])
                { // 노드 j를 거쳐 v로 가는 경로가 더 짧은 경우
                    dist[v] = dist[j] + w;
                }
            }
        }
    }

    for (int j = 1; j <= n; j++)
    { // Check for negative weight cycles: 한번 더 반복
        for (auto &edge : graph[j])
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[j] != INT_MAX && dist[j] + w < dist[v])
            {              // 음수 사이클이 존재하는 경우 (업데이트되면 존재)
                return {}; // 빈 벡터 반환
            }
        }
    }

    return dist; // 최단 거리 반환
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<vector<pair<long long, long long>>> graph(N + 1);
    for (int i = 0; i < M; i++)
    {
        long long u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    vector<long long> distances = bellman_ford(1, N, graph);
    if (distances.empty())
    {
        cout << -1 << '\n';
        return 0;
    }
    for (int i = 2; i <= N; i++)
    {
        if (distances[i] == INT_MAX)
            cout << -1 << '\n';
        else
            cout << distances[i] << '\n';
    }
}