#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> items;

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

    int N, m, r; // N: 정점의 수, m: 수색 범위, r: 길 개수
    int item;
    int max_item = 0;
    cin >> N >> m >> r;

    for (int i = 0; i < N; ++i)
    {
        cin >> item;
        items.push_back(item);
    }

    adj.resize(N + 1);
    for (int i = 0; i < r; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
        adj[b].push_back({a, w}); // 양방향
    }

    for (int i = 1; i <= N; ++i)
    {
        int temp = 0;
        vector<int> dist = dijkstra(i, N);
        for (int j = 1; j <= N; ++j)
        {
            if (dist[j] <= m)
            { // 수색 범위 내에 있는 경우
                temp += items[j - 1];
            }
        }
        max_item = max(max_item, temp);
    }

    cout << max_item;
    return 0;
}