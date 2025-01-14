#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int to, cost;
    bool operator>(const Edge &other) const
    {
        return cost > other.cost;
    }
};

vector<vector<Edge>> adj;
vector<bool> visited;

int prim(int N)
{ // prim algorithm : O(ElogV) -> 작은 것부터 선택
    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    pq.push({1, 0}); // Start from node 1
    int total_cost = 0;
    int max_cost = 0;

    while (!pq.empty())
    {
        Edge curr = pq.top();
        pq.pop();

        if (visited[curr.to])
            continue;
        visited[curr.to] = true;
        total_cost += curr.cost;
        max_cost = max(max_cost, curr.cost);

        for (const Edge &next : adj[curr.to])
        {
            if (!visited[next.to])
            {
                pq.push(next);
            }
        }
    }

    return total_cost - max_cost; // Subtract the maximum cost edge
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 도시의 수, M: 도로의 수
    cin >> N >> M;

    adj.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int u, v, cost;
        cin >> u >> v >> cost;
        adj[u].push_back({v, cost});
        adj[v].push_back({u, cost});
    }

    int result = prim(N);
    cout << result;

    return 0;
}