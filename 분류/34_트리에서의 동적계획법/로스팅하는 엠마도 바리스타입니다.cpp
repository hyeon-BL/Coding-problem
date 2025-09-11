#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Edge
{
    int to;
    int weight;
};

int N;
vector<vector<Edge>> tree;
vector<long long> D; // 각 노드의 거리 합 저장
vector<int> sub;     // 각 노드의 서브트리 크기 저장

// DFS로 서브트리 크기와 루트 노드의 거리 합 계산
void dfs(int node, int parent)
{
    sub[node] = 1; // 현재 노드 포함
    for (const auto &edge : tree[node])
    {
        int next = edge.to, weight = edge.weight;
        if (next == parent)
            continue; // 부모 노드로 돌아가지 않음
        dfs(next, node);
        sub[node] += sub[next];           // 서브트리 크기 업데이트
        D[1] += 1LL * weight * sub[next]; // 루트 노드 거리 합 계산
    }
}

// DFS로 각 노드의 거리 합 계산
void go(int node, int parent)
{
    for (const auto &edge : tree[node])
    {
        int next = edge.to, weight = edge.weight;
        if (next == parent)
            continue; // 부모 노드로 돌아가지 않음
        D[next] = D[node] + 1LL * weight * (N - sub[next]) - 1LL * weight * sub[next];
        go(next, node);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    tree.resize(N + 1);
    D.resize(N + 1, 0);
    sub.resize(N + 1, 0);

    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    // 루트 노드에서 시작하여 거리 합 계산
    dfs(1, 0); // 루트 노드의 거리 합 계산
    go(1, 0);  // 각 노드의 거리 합 계산

    // 결과 출력
    for (int i = 1; i <= N; i++)
        cout << D[i] << "\n";

    return 0;
}

/* N * N 2차원 배열 => 메모리 초과(300,000 * 300,000 = 90,000,000,000 byte = 약 90GB)
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct Edge
{
    int to;
    int weight;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<vector<int>> dist(N + 1, vector<int>(N + 1, INT_MAX)); // dist[i][j]: i에서 j로 가는 최소 비용

    for (int i = 1; i <= N; i++)
    {
        dist[i][i] = 0; // 자기 자신으로 가는 거리는 0
    }

    vector<vector<Edge>> tree(N + 1);
    for (int i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
        dist[u][v] = w;
        dist[v][u] = w;
    }

    // Floyd-Warshall Algorithm
    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }

    // 출력
    for (int i = 1; i <= N; i++)
    {
        int sum = 0;
        for (int j = 1; j <= N; j++)
        {
            if (dist[i][j] != INT_MAX)
            {
                sum += dist[i][j];
            }
        }
        cout << sum << "\n";
    }

    return 0;
}
*/