#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N : 가수의 수, M : 보조 PD의 수
    cin >> N >> M;
    vector<vector<int>> graph(N + 1); // graph[i] = i번 가수 이후 순서에 올 가수들
    vector<int> inDegree(N + 1, 0);   // 보조 PD가 담당하지 않은 가수도 포함

    for (int i = 0; i < M; i++)
    {
        int k; // 보조 PD가 담당한 가수의 수
        cin >> k;
        vector<int> pd(k);
        for (int j = 0; j < k; j++)
        {
            cin >> pd[j];
        }
        for (int j = 0; j < k - 1; j++)
        {
            graph[pd[j]].push_back(pd[j + 1]);
            inDegree[pd[j + 1]]++;
        }
    }

    // Topological Sort
    queue<int> q;
    for (int i = 1; i <= N; i++)
    {
        if (inDegree[i] == 0)
        { // 먼저 시작할 수 있는 가수
            q.push(i);
        }
    }

    vector<int> result;
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        result.push_back(curr);

        for (int next : graph[curr])
        { // curr 이후 순서에 올 가수들
            inDegree[next]--;
            if (inDegree[next] == 0)
            {
                q.push(next);
            }
        }
    }

    if (result.size() == N)
    { // 모든 가수를 정렬할 수 있는 경우
        for (int i : result)
        {
            cout << i << "\n";
        }
    }
    else
    {
        cout << "0";
    }
}