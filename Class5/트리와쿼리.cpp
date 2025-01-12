#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> tree;
vector<int> subtree_size;

void dfs(int node, int parent)
{
    subtree_size[node] = 1; // 자기 자신을 포함하므로 1로 초기화
    for (int child : tree[node])
    {
        if (child != parent)
        {
            dfs(child, node);
            subtree_size[node] += subtree_size[child];
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, R, Q; // N: 정점의 수, R: 루트 번호, Q: 쿼리 수
    cin >> N >> R >> Q;

    tree.resize(N + 1);            // 1-based indexing(adjacency list)
    subtree_size.resize(N + 1, 0); // 각 정점의 서브트리 크기

    for (int i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    // Root에서 시작하여 각 정점의 서브트리 크기 계산
    dfs(R, -1);

    for (int i = 0; i < Q; i++)
    {
        int query;
        cin >> query;
        cout << subtree_size[query] << "\n";
    }

    return 0;
}