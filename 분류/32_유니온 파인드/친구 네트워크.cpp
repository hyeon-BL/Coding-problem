#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

struct UnionFind
{
    vector<int> parent;
    vector<int> size; // 집합의 크기 저장 -> 재탐색할 필요 없이 시간 복잡도 개선

    UnionFind(int n) : parent(n + 1), size(n + 1, 1)
    {
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
        }
    }

    int find(int x)
    {
        if (parent[x] != x)
        {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    int unite(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        }
        return size[rootX];
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int F;
        cin >> F;

        UnionFind uf(2 * F);
        unordered_map<string, int> nameToId;
        int id = 1;

        for (int i = 0; i < F; i++)
        {
            string name1, name2;
            cin >> name1 >> name2;

            if (nameToId.find(name1) == nameToId.end())
            {
                nameToId[name1] = id++;
            }
            if (nameToId.find(name2) == nameToId.end())
            {
                nameToId[name2] = id++;
            }
            cout << uf.unite(nameToId[name1], nameToId[name2]) << "\n";
        }
    }
}