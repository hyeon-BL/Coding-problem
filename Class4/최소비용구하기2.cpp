#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adj;

vector<pair<int, vector<int>>> dijkstra(int start, int N)
{ // 다익스트라 알고리즘(O(ElogV))
    vector<pair<int, vector<int>>> dist(N + 1, {INT_MAX, vector<int>()});
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start].first = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curr_dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if (curr_dist > dist[curr].first)
            continue;

        for (auto &edge : adj[curr])
        {
            int next = edge.first;
            int weight = edge.second;
            if (dist[curr].first + weight < dist[next].first)
            {
                dist[next].first = dist[curr].first + weight;
                dist[next].second = dist[curr].second;
                dist[next].second.push_back(curr);
                pq.push({dist[next].first, next});
            }
        }
    }

    return dist; // start에서 모든 정점으로의 최단 경로 반환
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    adj.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, weight});
    }
    int start, end, mincost = 0;
    cin >> start >> end;

    // <최단 거리, 경로>
    vector<pair<int, vector<int>>> dist = dijkstra(start, N);

    cout << dist[end].first << '\n'
         << dist[end].second.size() + 1 << '\n';
    for (auto &node : dist[end].second)
    {
        cout << node << ' ';
    }
    cout << end;
}