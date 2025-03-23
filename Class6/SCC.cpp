#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <functional>
using namespace std;

void kosaraju(int N, const vector<vector<int>> &graph)
{
    vector<vector<int>> transpose(N + 1); // 역방향 그래프
    vector<bool> visited(N + 1, false);
    stack<int> order;         // 끝나는 순서대로 정점을 저장
    vector<vector<int>> sccs; // SCC 목록

    // Step 1: DFS로 그래프를 탐색하며 끝나는 순서대로 정점을 저장
    function<void(int)> dfs1 = [&](int node)
    {
        visited[node] = true;
        for (int next : graph[node])
        {
            if (!visited[next])
                dfs1(next);
        }
        order.push(node);
    };

    for (int i = 1; i <= N; i++)
    { // 모든 정점에 대해
        if (!visited[i])
            dfs1(i);
    }

    // Step 2: 그래프 역추적
    for (int u = 1; u <= N; u++)
    {
        for (int v : graph[u])
        {
            transpose[v].push_back(u);
        }
    }

    // Step 3: 역추적된 그래프를 DFS로 탐색하며 SCC 찾기
    fill(visited.begin(), visited.end(), false);
    function<void(int, vector<int> &)> dfs2 = [&](int node, vector<int> &component)
    {
        visited[node] = true;
        component.push_back(node);
        for (int next : transpose[node])
        {
            if (!visited[next])
                dfs2(next, component);
        }
    };

    while (!order.empty())
    {
        int node = order.top();
        order.pop();
        if (!visited[node])
        {
            vector<int> component;
            dfs2(node, component);
            sccs.push_back(component);
        }
    }

    // SCC 출력
    cout << sccs.size() << '\n';
    for (auto &scc : sccs)
        sort(scc.begin(), scc.end());
    sort(sccs.begin(), sccs.end(), [](const vector<int> &a, const vector<int> &b)
         { return a[0] < b[0]; });

    for (auto &scc : sccs)
    {
        for (int node : scc)
            cout << node << ' ';
        cout << "-1" << '\n';
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int V, E; // V: 정점의 개수, E: 간선의 개수
    cin >> V >> E;

    vector<vector<int>> graph(V + 1); // Adjacency list for SCC detection

    for (int i = 0; i < E; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b); // For SCC detection
    }

    kosaraju(V, graph);

    return 0;
}