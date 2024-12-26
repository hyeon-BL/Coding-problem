#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start, int N)
{ // 다익스트라 알고리즘
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr])
            continue;

        for (auto &edge : adj[curr])
        {
            int next = edge.first;
            int weight = edge.second;
            if (dist[curr] + weight < dist[next])
            {
                dist[next] = dist[curr] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    return dist; // 최단 거리로 가는 경로 반환
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, E, start; // N: 정점의 수, E: 간선의 수, start: 시작 정점
    cin >> N >> E;
    cin >> start;
    adj.resize(N + 1);
    for (int i = 0; i < E; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w}); // directed graph
    }

    vector<int> dist = dijkstra(start, N);
    for (int i = 1; i <= N; ++i)
    {
        if (dist[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << dist[i] << '\n';
    }
    return 0;
}