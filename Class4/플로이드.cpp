#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

/*
floayd_warshall algorithm
- 모든 정점 쌍 사이의 최단 거리를 구하는 알고리즘
- 시간 복잡도: O(n^3)
- subpath of shortest path is also shortest path
*/

void floyd_warshall(vector<vector<int>> &dist, int n)
{
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] < INF && dist[k][j] < INF)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m; // n: 정점의 개수, m: 간선의 개수

    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF)); // dist[i][j]: i에서 j로 가는 최단 거리
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        dist[a][b] = min(dist[a][b], w); // handle multiple edges
    }

    floyd_warshall(dist, n);

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (dist[i][j] == INF)
            {
                cout << "0 ";
            }
            else
            {
                cout << dist[i][j] << ' ';
            }
        }
        cout << '\n';
    }

    return 0;
}