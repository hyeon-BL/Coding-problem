#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

const int MAXN = 100001;
const int LOG = 17; // log2(MAXN) + 1
vector<pair<int, int>> adj[MAXN];
int depth[MAXN];       // 깊이
int parent[MAXN][LOG]; // 부모 노드
int dist[MAXN];        // 루트 노드로부터의 거리

void dfs(int v, int p, int d, int w)
{ // 깊이와 부모 노드 계산
    // v: 현재 노드, p: 부모 노드, d: 깊이, w: 루트 노드로부터의 거리
    depth[v] = d;
    parent[v][0] = p;
    dist[v] = w;
    for (auto &edge : adj[v])
    {
        int to = edge.first;
        int weight = edge.second;
        if (to != p)
        {
            dfs(to, v, d + 1, w + weight);
        }
    }
}

void preprocess(int n)
{ // Sparse Table을 사용하여 LCA 계산
    // LCA: 두 정점의 가장 가까운 공통 조상
    for (int j = 1; j < LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            if (parent[i][j - 1] != -1)
            {
                parent[i][j] = parent[parent[i][j - 1]][j - 1];
            }
        }
    }
}

int lca(int u, int v)
{
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }
    int diff = depth[u] - depth[v];
    for (int i = 0; i < LOG; i++)
    { // 깊이를 맞춰줌
        if ((diff >> i) & 1)
        {
            u = parent[u][i];
        }
    }
    if (u == v)
    {
        return u;
    }
    for (int i = LOG - 1; i >= 0; i--)
    { // 두 정점이 같은 조상을 가질 때까지 올라감
        if (parent[u][i] != parent[v][i])
        {
            u = parent[u][i];
            v = parent[v][i];
        }
    }
    return parent[u][0];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    // 초기화
    fill(depth, depth + N + 1, -1);
    fill(dist, dist + N + 1, 0);
    for (int i = 0; i <= N; i++)
    {
        fill(parent[i], parent[i] + LOG, -1);
    }

    // DFS를 사용하여 깊이와 부모 노드 계산
    dfs(1, -1, 0, 0);

    // Sparse Table을 사용하여 LCA 계산
    preprocess(N);

    int M;
    cin >> M;
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        int ancestor = lca(u, v);
        int distance = dist[u] + dist[v] - 2 * dist[ancestor];
        cout << distance << '\n';
    }

    return 0;
}

/*
이 문제는 '트리'라는 특성을 이용하여 풀 수 있다.
트리에서 두 정점 사이의 거리는 항상 유일하다.
따라서 두 정점 사이의 거리를 구할 때 '그래프'에서 사용하는 다익스트라 알고리즘이나 플로이드-워셜 알고리즘을 사용할 필요가 없다.


시간 초과 : 플로이드-워셜 알고리즘을 수행하면 시간복잡도가 O(N^3)이 되어 시간 초과
    // 플로이드-워셜 알고리즘
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

*/

/*
시간 초과 : 각 쌍마다 BFS를 수행하면 시간복잡도가 O(NM)이 되어 시간 초과
for (int i = 0; i < M; i++)
{
    int u, v;
    cin >> u >> v;
    unordered_map<int, int> dist;
    dist[u] = 0;
    vector<int> q = {u};
    for (int j = 0; j < q.size(); j++)
    {
        int cur = q[j];
        for (Edge &e : adj[cur])
        {
            if (dist.find(e.to) == dist.end())
            {
                dist[e.to] = dist[cur] + e.weight;
                q.push_back(e.to);
            }
        }
    }
    cout << dist[v] << '\n';
}
*/