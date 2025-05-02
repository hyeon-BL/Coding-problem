#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>> graph; // adjacency list (node, weight)
vector<vector<int>> reverseGraph;     // shortest path 찾기 위한 역방향 그래프
vector<int> dist;                     // 최단 거리 저장
vector<vector<bool>> isShortestPath;  // 최단 경로 여부 저장

void dijkstra(int start, int N)
{
    dist.assign(N, 1e9); // 거리 초기화
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (d > dist[u])
            continue;

        for (auto &edge : graph[u])
        {
            int v = edge.first;  // 연결된 노드
            int w = edge.second; // 가중치
            if (dist[v] > dist[u] + w)
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
}

void markShortestPaths(int start, int end)
{
    queue<int> q;
    q.push(end);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : reverseGraph[u])
        {
            for (auto &edge : graph[v])
            {
                if (edge.first == u && dist[v] + edge.second == dist[u])
                {
                    if (!isShortestPath[v][u])
                    {
                        isShortestPath[v][u] = true;
                        q.push(v);
                    }
                    break;
                }
            }
        }
    }
}

void removeShortestPathEdges(int start, int end)
{
    for (int u = 0; u < graph.size(); u++)
    {
        for (auto &edge : graph[u])
        {
            int v = edge.first;
            if (isShortestPath[u][v])
            {
                edge.second = 1e9; // 간선 제거
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        int N, M; // N: 장소의 수, M: 도로의 수
        cin >> N >> M;
        if (N == 0 && M == 0)
            break; // 입력 종료 조건

        int S, D; // S: 시작 장소, D: 도착 장소
        cin >> S >> D;

        graph.assign(N + 1, vector<pair<int, int>>());            // 그래프 초기화
        reverseGraph.assign(N + 1, vector<int>());                // 역방향 그래프 초기화
        isShortestPath.assign(N + 1, vector<bool>(N + 1, false)); // 최단 경로 여부 초기화

        for (int i = 0; i < M; i++)
        {
            int u, v, p; // u: 출발 장소, v: 도착 장소, p: 거리
            cin >> u >> v >> p;
            graph[u].push_back({v, p});   // 그래프에 간선 추가
            reverseGraph[v].push_back(u); // 역방향 그래프에 간선 추가
        }

        dijkstra(S, N);                // 다익스트라 알고리즘 수행
        markShortestPaths(S, D);       // 최단 경로 표시
        removeShortestPathEdges(S, D); // 최단 경로 간선 제거
        dijkstra(S, N);                // 다시 다익스트라 알고리즘 수행

        if (dist[D] == 1e9)
        {                       // 도착 장소에 도달할 수 없는 경우
            cout << -1 << "\n"; // -1 출력
        }
        else
        {
            cout << dist[D] << "\n"; // 최단 거리 출력
        }
    }
}