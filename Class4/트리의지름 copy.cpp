#include <iostream>
#include <vector>
using namespace std;

/*
strongly connected component와 비슷한 방식

1. 트리의 지름은 트리의 임의의 두 정점 사이의 거리 중 최대값이다.
2. 임의의 정점에서 가장 먼 정점을 찾는다.
3. 그 정점에서 가장 먼 정점까지의 거리가 트리의 지름이다.
*/

/*
adjcency list : O(V+E) -> sparse graph에서 메모리 절약
adjcency matrix : O(V^2) -> dense graph에서 시간 절약
*/

vector<vector<pair<int, int>>> adj; // 인접 리스트 -> memory save
vector<bool> visited;
int max_dist = 0;
int farthest_node = 0;

void dfs(int node, int dist)
{
    visited[node] = true;

    if (dist > max_dist)
    {
        max_dist = dist;
        farthest_node = node;
    }

    for (auto &next : adj[node])
    {
        int next_node = next.first;
        int weight = next.second;
        if (!visited[next_node])
        {
            dfs(next_node, dist + weight);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    adj.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        int a;
        cin >> a;
        while (true)
        {
            int b, w;
            cin >> b;
            if (b == -1)
                break;
            cin >> w;
            adj[a].push_back({b, w});
        }
    }

    // First DFS to find one end of the diameter
    fill(visited.begin(), visited.end(), false);
    dfs(1, 0);

    // Second DFS from the farthest node to find the diameter
    fill(visited.begin(), visited.end(), false);
    max_dist = 0;
    dfs(farthest_node, 0);

    cout << max_dist;
    return 0;
}