#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void swapNodes(int u, int v, vector<vector<int>> &graph, vector<int> &indegree)
{
    // Check if edge u -> v exists
    auto it = find(graph[u].begin(), graph[u].end(), v);
    if (it != graph[u].end())
    {
        // Remove edge u -> v
        graph[u].erase(it);
        indegree[v]--;

        // Add edge v -> u
        graph[v].push_back(u);
        indegree[u]++;
    }
    else
    {
        // Otherwise, edge v -> u exists
        auto it = find(graph[v].begin(), graph[v].end(), u);
        if (it != graph[v].end())
        {
            // Remove edge v -> u
            graph[v].erase(it);
            indegree[u]--;

            // Add edge u -> v
            graph[u].push_back(v);
            indegree[v]++;
        }
    }
}

vector<int> topologicalSort(int n, vector<vector<int>> &graph, vector<int> &indegree)
{
    queue<int> q;
    vector<int> result;

    // Initialize the queue with nodes having in-degree 0
    for (int i = 1; i <= n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    { // Process nodes in topological order
        if (q.size() > 1)
        {
            // Ambiguity detected
            return {};
        }

        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int next : graph[curr])
        {
            indegree[next]--;
            if (indegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    // If result size is less than n, there's a cycle
    if (result.size() < n)
    {
        return {}; // Return empty to indicate invalid topological order
    }

    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> indegree(n + 1, 0);
        vector<vector<int>> graph(n + 1);

        // Read initial ranking
        vector<int> ranking(n);
        for (int i = 0; i < n; i++)
        {
            cin >> ranking[i];
        }

        // Build the graph based on the initial ranking
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                graph[ranking[i]].push_back(ranking[j]);
                indegree[ranking[j]]++;
            }
        }

        int m;
        cin >> m;

        // Process swaps
        while (m--)
        {
            int u, v;
            cin >> u >> v;
            swapNodes(u, v, graph, indegree);
        }

        // Perform topological sort
        vector<int> result = topologicalSort(n, graph, indegree);
        if (result.empty())
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            for (int x : result)
            {
                cout << x << " ";
            }
            cout << "\n";
        }
    }
}