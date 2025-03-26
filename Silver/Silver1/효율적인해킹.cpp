#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> adj; // 인접 리스트
vector<int> visited;     // 방문 여부 저장용 배열
vector<int> memo;        // 결과 저장용 memoization 배열

int dfs(int node)
{
    visited[node] = 1;
    int count = 1;
    for (int neighbor : adj[node])
    {
        if (!visited[neighbor])
            count += dfs(neighbor);
    }
    return memo[node] = count; // 결과 저장
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    adj.resize(N + 1);
    visited.resize(N + 1, 0);
    memo.resize(N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a); // 역방향 그래프 (바이러스가 퍼지는 방향)
    }

    int maxCount = 0;
    vector<int> result;
    for (int i = 1; i <= N; i++)
    {
        fill(visited.begin(), visited.end(), 0); // 방문 배열 초기화
        int count = dfs(i);
        if (count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(i);
        }
        else if (count == maxCount)
        {
            result.push_back(i);
        }
    }

    for (int node : result)
    {
        cout << node << " ";
    }
}