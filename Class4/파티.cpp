#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adj;

vector<int> dijkstra(int start, int N)
{ // 다익스트라 알고리즘(O(ElogV))
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

    return dist; // start에서 모든 정점으로의 최단 경로 반환
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, x; // N: 정점의 수, M: 간선의 수, x: 중간 지점
    int longest = 0;

    cin >> N >> M >> x;

    adj.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({b, t}); // a에서 b로 가는데 t시간이 걸림(단방향)
    }

    vector<int> dist_from_x = dijkstra(x, N);

    for (int i = 1; i <= N; ++i)
    {
        if (i == x)
            continue;
        vector<int> dist_to_x = dijkstra(i, N);
        if (dist_to_x[x] != INT_MAX && dist_from_x[i] != INT_MAX)
        { // i에서 x로 가는 경로와 x에서 i로 가는 경로가 존재하는 경우
            longest = max(longest, dist_to_x[x] + dist_from_x[i]);
        }
    }

    cout << longest;
    return 0;
}