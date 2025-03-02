#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> edge[1000001];
vector<vector<int>> dp;
vector<bool> visited;

void dfs(int node)
{
    visited[node] = true;
    dp[node][0] = 0; // early adopter가 아닌 경우
    dp[node][1] = 1; // early adopter인 경우

    for (int neighbor : edge[node])
    { // 모든 이웃 노드에 대해
        if (!visited[neighbor])
        {
            dfs(neighbor);
            // early adopter가 아닌 경우 -> 이웃 노드는 early adopter여야 함
            dp[node][0] += dp[neighbor][1];

            // early adopter인 경우 -> 이웃 노드는 early adopter여도 되고 아니어도 됨
            dp[node][1] += min(dp[neighbor][0], dp[neighbor][1]);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N; // 노드 수
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    dp.resize(N + 1, vector<int>(2, 0));
    visited.resize(N + 1, false);

    dfs(1);

    cout << min(dp[1][0], dp[1][1]);
    return 0;
}