#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 도시의 개수, M: 도로의 개수
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1);        // Adjacency list
    vector<vector<pair<int, int>>> reverseAdj(N + 1); // Reverse adjacency list
    vector<int> inDegree(N + 1, 0);                   // 위상 정렬을 위한 in-degree
    vector<int> time(N + 1, 0);                       // 각 도시까지의 최대 소요 시간

    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        reverseAdj[b].push_back({a, c}); // 역 추적을 위한 역방향 그래프
        inDegree[b]++;
    }

    int start, end; // 시작 도시, 도착 도시
    cin >> start >> end;

    // Step 1: Topological Sort
    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        for (pair<int, int> p : adj[cur])
        {
            int next = p.first;
            int cost = p.second;
            time[next] = max(time[next], time[cur] + cost); // 다음 도시까지의 최대 소요 시간 갱신
            if (--inDegree[next] == 0)
                q.push(next);
        }
    }

    int maxCost = time[end];

    // Step 2: Reverse traversal (DFS)
    vector<bool> visited(N + 1, false);
    int roadCount = 0;
    queue<int> reverseQ;
    reverseQ.push(end);
    visited[end] = true;

    while (!reverseQ.empty())
    {
        int cur = reverseQ.front();
        reverseQ.pop();
        for (pair<int, int> p : reverseAdj[cur])
        {
            int prev = p.first;
            int cost = p.second;
            if (time[cur] - cost == time[prev])
            { // 최대 소요 시간이 같은 경우
                roadCount++;
                if (!visited[prev])
                {
                    visited[prev] = true;
                    reverseQ.push(prev);
                }
            }
        }
    }

    cout << maxCost << '\n'
         << roadCount;
    return 0;
}

/*
시간초과 : DFS로 풀었을 때
모든 경로를 탐색하면서 최대 경로를 찾아야 하므로 시간복잡도가 O(2^N)
=> reverse traversal을 이용한 DFS로 최적화
=> 최대 소요 시간을 구한 후, 역 추적을 통해 최대 소요 시간을 가지는 경로의 개수를 구함

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 도시의 개수, M: 도로의 개수
    cin >> N >> M;

    vector<vector<pair<int, int>>> adj(N + 1); // Adjacency list
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int start, end; // 시작 도시, 도착 도시
    cin >> start >> end;

    vector<bool> visited(N + 1, false);
    int maxCost = 0;
    set<pair<int, int>> uniqueEdges; // Set to store unique edges in maximum-cost paths

    function<void(int, int, vector<pair<int, int>> &)> dfs = [&](int node, int currentCost, vector<pair<int, int>> &pathEdges)
    {
        if (node == end)
        {
            if (currentCost > maxCost)
            { // 새로운 최대 경로를 찾았을 때
                maxCost = currentCost;
                uniqueEdges.clear(); // Clear previous edges
                for (const auto &edge : pathEdges)
                    uniqueEdges.insert(edge);
            }
            else if (currentCost == maxCost)
            { // 최대 경로가 여러 개일 때
                for (const auto &edge : pathEdges)
                    uniqueEdges.insert(edge); // Add edges to set
            }
            return;
        }
        visited[node] = true;
        for (pair<int, int> next : adj[node])
        {
            if (!visited[next.first])
            {
                pathEdges.push_back({node, next.first}); // Add edge to path
                dfs(next.first, currentCost + next.second, pathEdges);
                pathEdges.pop_back(); // Backtrack
            }
        }
        visited[node] = false; // Backtrack
    };

    vector<pair<int, int>> pathEdges;
    dfs(start, 0, pathEdges);

    cout << maxCost << '\n'
         << uniqueEdges.size();
    return 0;
}

*/