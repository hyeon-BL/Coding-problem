#include <iostream>
#include <vector>
using namespace std;

struct UnionFind
{
    vector<int> parent;

    UnionFind(int n) : parent(n + 1)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]); // Path compression
        return parent[x];
    }

    void unionSets(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    UnionFind uf(N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int x;
            cin >> x;
            if (x)
                uf.unionSets(i, j);
        }
    }

    int temp;
    cin >> temp;
    for (int i = 1; i < M; i++)
    {
        int c;
        cin >> c;
        if (uf.find(temp) != uf.find(c))
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}