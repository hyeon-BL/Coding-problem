#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
vector<int> visited;
vector<int> order;

void bfs(int R)
{
    queue<int> q;
    q.push(R);
    visited[R] = 1;

    int cnt = 1;      // 방문 순서 카운트
    order[R] = cnt++; // 방문 순서 기록

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (int next : adj[curr])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = 1;
                order[next] = cnt++;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, R;
    cin >> N >> M >> R;

    visited.resize(N + 1, 0);
    order.reserve(N + 1);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end(), greater<int>());
    }

    bfs(R);
    for (int i = 1; i <= N; i++)
    {
        cout << order[i] << '\n';
    }
}