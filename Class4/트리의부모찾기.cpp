#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int> &parent, vector<vector<int>> &adj)
{
    for (int neighbor : adj[node]) // visit all neighbors
    {
        if (parent[neighbor] == 0)
        { // if the neighbor has not been visited
            parent[neighbor] = node;
            dfs(neighbor, parent, adj);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    for (int i = 1; i < N; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> parent(N + 1, 0); // parent[i] will store the parent of node i
    parent[1] = 1;                // root node
    dfs(1, parent, adj);

    for (int i = 2; i <= N; i++)
    {
        cout << parent[i] << '\n';
    }

    return 0;
}