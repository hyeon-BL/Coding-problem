#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
1. N개의 문제를 풀어야 함
2. M개의 문제를 먼저 풀어야 함 -> 위상정렬
3. 가능하면 작은 번호의 문제부터 풀어야 함 -> 최소힙
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 문제 수, M: 먼저 풀어야 하는 문제 수
    cin >> N >> M;

    vector<vector<int>> adj(N + 1); // adjaceny list
    vector<int> inDegree(N + 1, 0); // in-degree
    for (int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++; // v를 풀기 위해서는 u를 먼저 풀어야 함
    }

    priority_queue<int, vector<int>, greater<int>> pq; // 최소 힙
    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        {
            pq.push(i);
        }
    }

    vector<int> result;
    while (!pq.empty())
    {
        int current = pq.top();
        pq.pop();
        result.push_back(current); // 현재 문제를 풀어서 결과에 추가

        for (int neighbor : adj[current])
        { // 현재 문제를 풀었으므로 이웃들의 in-degree를 감소
            inDegree[neighbor]--;
            if (inDegree[neighbor] == 0)
            {
                pq.push(neighbor);
            }
        }
    }

    for (int problem : result)
    {
        cout << problem << " ";
    }
}