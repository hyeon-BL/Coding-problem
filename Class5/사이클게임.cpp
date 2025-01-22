#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    vector<int> next;
};

// Union-Find data structure
/*
union-find는 노드들이 서로소 집합으로 나뉘어져 있을 때, 두 노드가 같은 집합에 속하는지 판별하는 알고리즘, 즉 사이클 판별하는데 주로 사용되는 알고리즘

*/

vector<int> parent, rank;

int find(int x)
{
    if (parent[x] != x)
    {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

bool unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);

    if (rootX != rootY)
    {
        if (::rank[rootX] > ::rank[rootY]) // ::rank: global variable
        {
            parent[rootY] = rootX;
        }
        else if (::rank[rootX] < ::rank[rootY])
        {
            parent[rootX] = rootY;
        }
        else
        {
            parent[rootY] = rootX;
            ::rank[rootX]++;
        }
        return false;
    }
    return true; // Cycle detected
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 정점의 개수, M: 간선의 개수
    cin >> N >> M;
    vector<Node> nodes(N + 1);

    parent.resize(N + 1);
    ::rank.resize(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int X, Y;
        cin >> X >> Y;
        if (unionSets(X, Y))
        {                  // O(logN)
            cout << i + 1; // Edge number that creates a cycle
            return 0;
        }
    }

    cout << 0; // No cycle found
}
