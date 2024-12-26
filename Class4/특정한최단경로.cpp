#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<bool> visited;

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

bool isPathConnected(const vector<int> &dist, int node)
{ // 시작 노드로부터 해당 노드까지의 거리가 INT_MAX가 아닌 경우 연결되어 있다고 판단
    return dist[node] != INT_MAX;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, E; // N: 정점의 수, E: 간선의 수
    cin >> N >> E;
    adj.resize(N + 1);
    for (int i = 0; i < E; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w});
    }
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> dist_from_1 = dijkstra(1, N);
    vector<int> dist_from_n1 = dijkstra(n1, N);
    vector<int> dist_from_n2 = dijkstra(n2, N);

    int path1 = dist_from_1[n1] + dist_from_n1[n2] + dist_from_n2[N]; // 1 -> n1 -> n2 -> N
    int path2 = dist_from_1[n2] + dist_from_n2[n1] + dist_from_n1[N]; // 1 -> n2 -> n1 -> N

    if (!isPathConnected(dist_from_1, n1) || !isPathConnected(dist_from_n1, n2) || !isPathConnected(dist_from_n2, N))
    {
        path1 = INT_MAX;
    }

    if (!isPathConnected(dist_from_1, n2) || !isPathConnected(dist_from_n2, n1) || !isPathConnected(dist_from_n1, N))
    {
        path2 = INT_MAX;
    }

    int result = min(path1, path2);
    if (result >= INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << result;
    }

    return 0;
}