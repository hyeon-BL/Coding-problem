#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_LOG = 20;   // 최대 깊이 (2^20 > 10^5)
vector<int> depth;        // 깊이 저장
vector<vector<int>> up;   // 조상 저장 (binary lifting) -> DP 테이블
vector<vector<int>> tree; // 트리 저장

void dfs(int node, int parent)
{
    depth[node] = depth[parent] + 1;
    up[node][0] = parent; // Direct parent

    // binary lifting: up[node][i] = node의 2^i번째 조상
    for (int i = 1; i < MAX_LOG; ++i)
    {
        up[node][i] = up[up[node][i - 1]][i - 1];
    }

    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node);
        }
    }
}

int lca(int u, int v)
{
    // u가 v보다 깊이가 깊도록 설정
    if (depth[u] < depth[v])
    {
        swap(u, v);
    }

    // u를 v와 같은 깊이로 맞춤
    for (int i = MAX_LOG - 1; i >= 0; --i)
    {
        if (depth[u] - (1 << i) >= depth[v])
        { // 너무 많이 리프팅하지 않도록 v의 깊이와 크거나 같은 경우에 리프팅
            u = up[u][i];
        }
    }

    // u와 v가 같아지면 LCA는 u (또는 v)
    if (u == v)
    {
        return u;
    }

    // u와 v를 리프팅하여 parent을 찾음
    for (int i = MAX_LOG - 1; i >= 0; --i)
    {
        if (up[u][i] != up[v][i])
        {
            u = up[u][i];
            v = up[v][i];
        }
    }

    // u(또는 v)의 부모가 LCA
    return up[u][0];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M; // N: 노드 개수, M: 쿼리 개수
    cin >> N;

    tree.resize(N + 1); // 1-indexed
    for (int i = 0; i < N - 1; ++i)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Preprocessing
    depth.resize(N + 1, 0);                    // 1-indexed
    up.assign(N + 1, vector<int>(MAX_LOG, 0)); // 1-indexed
    dfs(1, 0);                                 // 1을 루트로 가정, 부모는 0

    cin >> M;
    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        cout << lca(u, v) << "\n";
    }

    return 0;
}

// 참고: https://4legs-study.tistory.com/121