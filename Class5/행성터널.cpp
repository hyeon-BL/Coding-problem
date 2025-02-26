#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Planet
{
    int x, y, z, index;
};

struct Edge
{
    int u, v, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

int find(vector<int> &parent, int u)
{
    if (parent[u] != u)
    {
        parent[u] = find(parent, parent[u]);
    }
    return parent[u];
}

void unite(vector<int> &parent, vector<int> &rank, int u, int v)
{
    int root_u = find(parent, u);
    int root_v = find(parent, v);
    if (root_u != root_v)
    {
        if (rank[root_u] > rank[root_v])
        {
            parent[root_v] = root_u;
        }
        else if (rank[root_u] < rank[root_v])
        {
            parent[root_u] = root_v;
        }
        else
        {
            parent[root_v] = root_u;
            rank[root_u]++;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;                  // 행성의 개수
    vector<Planet> planets(N); // 행성들의 정보
    for (int i = 0; i < N; i++)
    {
        cin >> planets[i].x >> planets[i].y >> planets[i].z;
        planets[i].index = i;
    }

    vector<Edge> edges; // 간선들의 정보(x, y, z)

    // x축 기준 edge 생성
    sort(planets.begin(), planets.end(), [](const Planet &a, const Planet &b)
         { return a.x < b.x; });
    for (int i = 1; i < N; i++)
    {
        edges.push_back({planets[i - 1].index, planets[i].index, abs(planets[i].x - planets[i - 1].x)});
    }

    // y축 기준 edge 생성
    sort(planets.begin(), planets.end(), [](const Planet &a, const Planet &b)
         { return a.y < b.y; });
    for (int i = 1; i < N; i++)
    {
        edges.push_back({planets[i - 1].index, planets[i].index, abs(planets[i].y - planets[i - 1].y)});
    }

    // z축 기준 edge 생성
    sort(planets.begin(), planets.end(), [](const Planet &a, const Planet &b)
         { return a.z < b.z; });
    for (int i = 1; i < N; i++)
    {
        edges.push_back({planets[i - 1].index, planets[i].index, abs(planets[i].z - planets[i - 1].z)});
    }

    // Kruskal Algorithm : Minimum Spanning Tree
    sort(edges.begin(), edges.end());
    vector<int> parent(N), rank(N, 0);
    for (int i = 0; i < N; i++)
    {
        parent[i] = i;
    }

    int min_cost = 0;
    for (const Edge &edge : edges)
    { // edge들을 오름차순으로 순회(가중치가 작은 순서대로)
        if (find(parent, edge.u) != find(parent, edge.v))
        { // cycle이 발생하지 않는 경우
            unite(parent, rank, edge.u, edge.v);
            min_cost += edge.weight;
        }
    }

    cout << min_cost;
    return 0;
}