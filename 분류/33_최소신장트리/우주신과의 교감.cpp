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

    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
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
    int N, M;
    cin >> N >> M;

    vector<pair<double, double>> coords(N);
    for (int i = 0; i < N; i++)
        cin >> coords[i].first >> coords[i].second;

    vector<Edge> edges;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            double weight = calculate_distance(coords[i], coords[j]);
            edges.push_back({i, j, weight});
        }
    }

    sort(edges.begin(), edges.end()); // Kruskal's algorithm을 위해 간선 가중치 기준 정렬

    UnionFind uf(N);
    for (int i = 0; i < M; i++)
    {
        int a, b; // 이미 연결된 통로 (입력된 좌표들의 순서)
        cin >> a >> b;
        uf.unite(a - 1, b - 1); // 0-indexed로 변환하여 union
    }

    // Kruskal's algorithm
    double total_weight = 0.0;
    for (const auto &edge : edges)
    {
        if (uf.find(edge.from) != uf.find(edge.to))
        {
            uf.unite(edge.from, edge.to);
            total_weight += edge.weight;
        }
    }

    cout.precision(2);
    cout << fixed;
    cout << total_weight;
    return 0;
}