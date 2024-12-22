#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();
unordered_map<int, vector<pair<int, int>>> graph;

vector<int> dijkstra(int start, int N)
{ // 다익스트라 알고리즘(우선순위 큐 사용) : O(ElogV)
    vector<int> dist(N + 1, INF);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int cost = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (cost > dist[node]) // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 길 경우
            continue;

        for (auto &edge : graph[node])
        {
            int nextNode = edge.first;
            int nextCost = cost + edge.second;

            if (nextCost < dist[nextNode])
            { // 현재 노드를 거쳐서 다른 노드로 이동하는 거리가 더 짧은 경우
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
        }
    }

    return dist;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    while (M--)
    {
        int snode, enode, weight;
        cin >> snode >> enode >> weight;
        graph[snode].push_back({enode, weight});
    }
    int start, end;
    cin >> start >> end;

    vector<int> dist = dijkstra(start, N);
    cout << dist[end];
}