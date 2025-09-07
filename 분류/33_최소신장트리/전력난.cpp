#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    UnionFind(int n) : parent(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
            parent[rootX] = rootY;
    }
};

struct Edge
{
    int from, to, weight;

    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    while (true)
    {
        int m, n;
        cin >> m >> n;

        if (n == 0 && m == 0)
            break;
        vector<Edge> edges;
        int total_weight = 0;
        for (int i = 0; i < n; i++)
        {
            Edge edge;
            cin >> edge.from >> edge.to >> edge.weight;
            edges.push_back(edge);
            total_weight += edge.weight;
        }

        sort(edges.begin(), edges.end());

        UnionFind uf(m);
        int mst_weight = 0;
        for (const Edge &edge : edges)
        {
            if (uf.find(edge.from) != uf.find(edge.to))
            {
                uf.unite(edge.from, edge.to);
                mst_weight += edge.weight;
            }
        }

        cout << total_weight - mst_weight << "\n";
    }
}