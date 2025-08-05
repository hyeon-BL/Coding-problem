#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> adj[100001];
vector<int> visited;
vector<int> order;

void dfs(int R, int &cnt)
{
    visited[R] = 1;   // 현재 노드 방문 처리
    order[R] = cnt++; // 방문 순서 기록

    for (int i = 0; i < adj[R].size(); i++)
    {
        int next = adj[R][i];
        if (!visited[next])
        {                   // 방문하지 않은 노드라면
            dfs(next, cnt); // 재귀적으로 DFS 호출
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
    order.resize(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i <= N; i++)
    {
        sort(adj[i].begin(), adj[i].end()); // 인접 리스트 정렬
    }

    int cnt = 1; // 방문 순서 카운트

    dfs(R, cnt); // DFS 시작

    for (int i = 1; i <= N; i++)
    {
        cout << order[i] << '\n'; // 방문 순서 출력
    }
}