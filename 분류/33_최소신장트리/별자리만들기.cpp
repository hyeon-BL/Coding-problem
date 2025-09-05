#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

double calculate_distance(const pair<double, double> &a, const pair<double, double> &b)
{
    double dx = a.first - b.first;
    double dy = a.second - b.second;
    return sqrt(dx * dx + dy * dy);
}

struct Edge
{
    int from, to;
    double weight;
};

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

int main()
{
    int n;
    cin >> n;

    vector<pair<double, double>> coords(n);
    for (int i = 0; i < n; i++)
        cin >> coords[i].first >> coords[i].second;

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            double weight = calculate_distance(coords[i], coords[j]);
            edges.push_back({i, j, weight});
        }
    }

    // Sort edges by weight
    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b)
         { return a.weight < b.weight; });

    // Kruskal's algorithm
    UnionFind uf(n);
    double total_weight = 0.0;

    for (const auto &edge : edges)
    { // 가장 작은 간선부터 확인,
        if (uf.find(edge.from) != uf.find(edge.to))
        { // 사이클이 발생하지 않는 경우에만 집합에 포함
            uf.unite(edge.from, edge.to);
            total_weight += edge.weight;
        }
    }

    cout.precision(2);
    cout << fixed;
    cout << total_weight;

    return 0;
}