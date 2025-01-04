#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/*
벨만포드의 본질 : 특정 정점에서 다른 정점으로 가는 최단 경로를 찾는 알고리즘
    - N-1번의 edge relaxation을 수행하여 최단 경로를 찾음
    - N번째 edge relaxation을 수행하여 negative weight cycle을 찾음
    - 이 문제에서는 특정 정점이 주어지지 않음, negative weight cycle이 존재하는지만 확인
    - INF를 사용하는 이유는 정점 간 '단절' 여부를 판단하기 위함

    - 즉, INF를 사용하지 않고 아무 정점에서 시작하면 time complexity, correctness 모두 문제 없음
*/

const int INF = 1e9;
struct Edge
{
    int from, to, weight;
};

bool bellman_ford(int N, int start, vector<Edge> &edges)
{
    vector<int> dist(N + 1, INF);
    dist[start] = 0;

    for (int i = 1; i <= N - 1; ++i)
    { // N-1번 edge relaxation -> O(VE)
        for (auto &edge : edges)
        { // 모든 edge에 대해 edge relaxation 수행
            int u = edge.from;
            int v = edge.to;
            int weight = edge.weight;
            if (dist[u] + weight < dist[v])
            { // dist[u] + weight가 dist[v]보다 작으면 갱신(INF는 문제 조건에 의해 필요 없음)
                dist[v] = dist[u] + weight;
            }
        }
    }

    for (auto &edge : edges)
    { // 한번 더 edge relaxation을 수행하여 negative weight cycle 검출
        int u = edge.from;
        int v = edge.to;
        int weight = edge.weight;
        if (dist[u] + weight < dist[v])
        {
            return true; // Negative weight cycle detected
        }
    }

    return false; // No negative weight cycle
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int TC;
    int N, M, W; // N: 정점의 수, M: 도로의 수, W: 웜홀의 수
    int S, E, T; // S: 시작점, E: 도착점, T: 소요 시간
    cin >> TC;

    while (TC--)
    {
        cin >> N >> M >> W;

        vector<Edge> edges;
        for (int i = 0; i < M; ++i)
        {
            cin >> S >> E >> T;
            edges.push_back({S, E, T});
            edges.push_back({E, S, T});
        }

        for (int i = 0; i < W; ++i)
        {
            cin >> S >> E >> T;
            edges.push_back({S, E, -T});
        }

        if (bellman_ford(N, 1, edges))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}

/*
O(N^2M) 풀이 -> 시간 초과
모든 정점에 대해 벨만포드 수행.
=> O(NM) * O(N) = O(N^2M)

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<vector<pair<int, int>>> adj;

bool bellman_ford(int start, int N)
{
    vector<int> dist(N + 1, INT_MAX);
    dist[start] = 0;

    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
        {
            for (auto &edge : adj[j])
            {
                int next = edge.first;
                int weight = edge.second;
                if (dist[j] != INT_MAX && dist[j] + weight < dist[next])
                {
                    dist[next] = dist[j] + weight;
                    if (i == N)
                        return true; // N번째 라운드에서도 값이 갱신된다면 음수 사이클 존재
                }
            }
        }
    }

    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int TC;
    int N, M, W; // N: 정점의 수, M: 도로의 수, W: 웜홀의 수
    int S, E, T; // S: 시작점, E: 도착점, T: 소요 시간

    cin >> TC;
    while (TC--)
    {
        cin >> N >> M >> W;

        adj.clear();
        adj.resize(N + 1);
        for (int i = 0; i < M; ++i)
        {
            cin >> S >> E >> T;
            adj[S].push_back({E, T});
            adj[E].push_back({S, T});
        }

        for (int i = 0; i < W; ++i)
        {
            cin >> S >> E >> T;
            adj[S].push_back({E, -T});
        }

        if (bellman_ford(1, N))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
*/