#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dist;

vector<vector<int>> floyd_warshall(int n)
{
    vector<vector<int>> track(n + 1, vector<int>(n + 1, -1));
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    track[i][j] = track[i][k] == -1 ? k : track[i][k]; // k가 경유지인 경우
                }
            }
    return track;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    dist.resize(N + 1, vector<int>(N + 1, 1e9));

    for (int i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }

    vector<vector<int>> track = floyd_warshall(N);
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j || dist[i][j] == 1e9)
                cout << 0 << ' ';
            else
                cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j || dist[i][j] == 1e9)
            {
                cout << 0 << '\n';
                continue;
            }

            vector<int> result;
            result.push_back(i);
            int cur = i;
            while (track[cur][j] != -1)
            { // i ~ j 사이 노드 추적
                result.push_back(track[cur][j]);
                cur = track[cur][j];
            }
            result.push_back(j);

            cout << result.size() << ' ';
            for (int k : result)
                cout << k << ' ';
            cout << '\n';
        }
    }
    return 0;
}