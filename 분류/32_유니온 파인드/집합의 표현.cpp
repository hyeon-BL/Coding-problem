#include <iostream>
#include <vector>
using namespace std;

class UnionFind
{
private:
    vector<int> parent, rank;

public:
    UnionFind(int n)
    {
        parent.resize(n + 1);  // tree representation
        rank.resize(n + 1, 1); // for balancing
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    void unionSets(int a, int b)
    {
        int rootA = find(a);
        int rootB = find(b);

        // parent[rootB] = rootA; // Union without rank consideration
        if (rootA != rootB)
        {
            if (rank[rootA] > rank[rootB])
            {
                parent[rootB] = rootA;
            }
            else if (rank[rootA] < rank[rootB])
            {
                parent[rootA] = rootB;
            }
            else
            {
                parent[rootB] = rootA;
                rank[rootA]++;
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    UnionFind uf(n);

    for (int i = 0; i < m; i++)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 0)
        {
            uf.unionSets(a, b);
        }
        else if (op == 1)
        {
            if (uf.find(a) == uf.find(b))
            {
                cout << "YES\n";
            }
            else
            {
                cout << "NO\n";
            }
        }
    }

    return 0;
}