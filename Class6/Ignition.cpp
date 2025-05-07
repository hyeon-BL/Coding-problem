#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> adj;
vector<vector<int>> dist;

/*
adjcency matrix: adj[i][j] = i에서 j까지의 가장 큰 가중치
dist[i][j] = i에서 j까지의 가장 작은 가중치

=> Floyd-Warshall 알고리즘을 사용하여 dist를 구함
=> 가장 큰 가중치 adj[i][j]를 사용하여 남은 경로를 구함(brute force)

*/

double Ignition(int N, int M)
{
    double fastest = INT_MAX; // 가장 빠른 경로의 시간
    double total;             // 모든 경로의 시간 합
    int length;               // 경로의 길이

    for (int start = 1; start <= N; ++start)
    {
        double slowest = 0; // 가장 느린 경로의 시간

        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                length = adj[i][j];

                if (length != -1)
                {
                    double remaining = length - (dist[start][j] - dist[start][i]);
                    if (remaining > 0)
                    {
                        total = (remaining / 2) + dist[start][j];
                        slowest = max(slowest, total);
                    }
                }
            }
        }
        fastest = min(fastest, slowest);
    }
    return fastest;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 정점의 수, M: 간선의 수
    cin >> N >> M;

    adj.assign(N + 1, vector<int>(N + 1, -1));
    dist.assign(N + 1, vector<int>(N + 1, INT_MAX));
    for (int i = 1; i <= N; ++i)
    {
        dist[i][i] = 0;
    }
    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;

        if (adj[u][v] == -1 || adj[u][v] < w)
        { // 가중치가 큰 간선으로 초기화
            adj[u][v] = w;
            adj[v][u] = w;
        }
        if (dist[u][v] == INT_MAX || dist[u][v] > w)
        { // 가중치가 작은 간선으로 초기화
            dist[u][v] = w;
            dist[v][u] = w;
        }
    }
    for (int k = 1; k <= N; ++k)
    {
        for (int i = 1; i <= N; ++i)
        {
            for (int j = 1; j <= N; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    double result = Ignition(N, M);
    cout << fixed;
    cout.precision(1);
    cout << result;
}

// reference: https://everenew.tistory.com/169
