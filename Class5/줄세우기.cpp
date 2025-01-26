#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> order(M);
    for (int i = 0; i < M; i++)
    { // 두 학생 사이의 키 순서 입력
        cin >> order[i].first >> order[i].second;
    }

    vector<vector<int>> adj(N + 1); // 인접 리스트
    vector<int> in_degree(N + 1, 0);

    for (int i = 0; i < M; i++)
    { // 특정 학생보다 키가 작은 학생들을 인접 리스트에 추가
        adj[order[i].first].push_back(order[i].second);
        in_degree[order[i].second]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (in_degree[i] == 0)
        { // 키가 가장 작은 학생부터 큐에 삽입
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int next : adj[curr])
        { // 큐에서 꺼낸 학생보다 키가 큰 학생들의 in_degree를 1씩 감소
            if (--in_degree[next] == 0)
            { // in_degree가 0이 되면 큐에 삽입
                q.push(next);
            }
        }
    }

    for (int i : result)
    {
        cout << i << " ";
    }

    return 0;
}