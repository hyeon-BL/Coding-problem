#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int node, vector<vector<int>> &graph, vector<vector<int>> &dp, vector<bool> &visited, vector<int> &arr)
{
    visited[node] = true;
    dp[node][1] = arr[node];

    for (int neighbor : graph[node])
    {
        if (!visited[neighbor])
        {
            dfs(neighbor, graph, dp, visited, arr);
            dp[node][0] += max(dp[neighbor][0], dp[neighbor][1]);
            dp[node][1] += dp[neighbor][0];
        }
    }
}

void find_independent_set(int node, vector<vector<int>> &graph, vector<vector<int>> &dp, vector<bool> &visited, vector<int> &independent_set, bool can_take)
{
    visited[node] = true;
    if (can_take && dp[node][1] > dp[node][0])
    { // 현재 노드를 독립 집합에 포함
        independent_set.push_back(node);
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                find_independent_set(neighbor, graph, dp, visited, independent_set, false);
            }
        }
    }
    else
    { // 현재 노드를 독립 집합에 포함하지 않음
        for (int neighbor : graph[node])
        {
            if (!visited[neighbor])
            {
                find_independent_set(neighbor, graph, dp, visited, independent_set, true);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<vector<int>> graph(n + 1);
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<vector<int>> dp(n + 1, vector<int>(2, 0)); // dp[i][0]: i가 인접할 때(독립 집합이 아닐 때), dp[i][1]: i가 인접하지 않을 때(독립 집합일 때)
    vector<bool> visited(n + 1, false);
    vector<int> independent_set;

    dfs(1, graph, dp, visited, arr);
    visited.assign(n + 1, false);
    find_independent_set(1, graph, dp, visited, independent_set, true);

    cout << max(dp[1][0], dp[1][1]) << "\n";
    sort(independent_set.begin(), independent_set.end());
    for (int node : independent_set)
    {
        cout << node << " ";
    }
    return 0;
}