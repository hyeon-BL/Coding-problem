#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isTree(int n, int start, vector<vector<int>> &adj, vector<bool> &visited)
{
    vector<int> parent(n + 1, -1);

    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int neighbor : adj[curr])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                parent[neighbor] = curr;
                q.push(neighbor);
            }
            else if (parent[curr] != neighbor)
            { // 이미 방문한 노드를 재방문하려고 할 때, 그 노드가 부모 노드가 아니라면 사이클
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int caseNumber = 1;
    while (true)
    {
        int n, m;
        cin >> n >> m;

        if (n == 0 && m == 0)
            break;

        vector<vector<int>> adj(n + 1);
        vector<bool> visited(n + 1, false);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int treeCount = 0;
        for (int i = 1; i <= n; i++) // Disconnected graph에서의 트리 개수 세기 위해 모든 정점 확인
            if (!visited[i])
                if (isTree(n, i, adj, visited))
                    treeCount++;

        cout << "Case " << caseNumber++ << ": ";
        if (treeCount == 0)
            cout << "No trees.\n";
        else if (treeCount == 1)
            cout << "There is one tree.\n";
        else
            cout << "A forest of " << treeCount << " trees.\n";
    }
}