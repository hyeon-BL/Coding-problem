#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Edge
{
    int from, to, weight;
    bool operator<(const Edge &other) const
    {
        return weight < other.weight;
    }
};

struct UnionFind
{
    vector<int> parent;

    UnionFind(int n) : parent(n)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y)
    {
        parent[find(x)] = find(y);
    }

    bool isConnected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int N, M;
vector<vector<int>> country;
vector<vector<bool>> visited;
vector<Edge> edges;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void bfs(int x, int y, int islandNum)
{ // BFS로 섬 번호 매기기
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    country[x][y] = islandNum;

    while (!q.empty())
    {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i], ny = cy + dy[i];
            if (nx >= 0 && nx < N && ny >= 0 && ny < M &&
                !visited[nx][ny] && country[nx][ny] == 1)
            {
                visited[nx][ny] = true;
                country[nx][ny] = islandNum;
                q.push({nx, ny});
            }
        }
    }
}

void findBridges(int islandNum)
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < M; y++)
        {
            if (country[x][y] != islandNum) // 현재 섬이 아니면 패스
                continue;

            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // 시작점이 바다여야 함 (현재 섬과 인접한 바다)
                if (nx < 0 || nx >= N || ny < 0 || ny >= M || country[nx][ny] != 0)
                    continue;

                int length = 0;
                while (true)
                {
                    if (nx < 0 || nx >= N || ny < 0 || ny >= M) // 지도 벗어남
                        break;

                    if (country[nx][ny] == islandNum) // 같은 섬으로 돌아옴
                        break;

                    if (country[nx][ny] > 0) // 다른 섬에 도달
                    {
                        if (length >= 2) // 다리 길이가 2 이상인 경우만
                        {
                            int from = islandNum, to = country[nx][ny];
                            edges.push_back({from, to, length});
                        }
                        break;
                    }

                    if (country[nx][ny] != 0) // 바다가 아닌 곳은 다리 건설 불가
                        break;

                    length++;
                    nx += dx[i]; // 같은 방향으로 계속 이동
                    ny += dy[i];
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    country = vector<vector<int>>(N, vector<int>(M));
    visited = vector<vector<bool>>(N, vector<bool>(M, false));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> country[i][j];

    int islandNum = 2;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            if (country[i][j] == 1 && !visited[i][j])
                bfs(i, j, islandNum++);

    for (int i = 2; i < islandNum; i++)
        findBridges(i);

    sort(edges.begin(), edges.end());

    UnionFind uf(islandNum);
    int mstWeight = 0, connected = 0;
    int islands = islandNum - 2; // 실제 섬의 개수

    for (const auto &edge : edges)
    {
        if (!uf.isConnected(edge.from, edge.to))
        {
            uf.unite(edge.from, edge.to);
            mstWeight += edge.weight;
            if (++connected == islands - 1)
            { // 모든 섬이 연결됨(edge 개수 == 섬 개수 - 1)
                cout << mstWeight << "\n";
                return 0;
            }
        }
    }

    cout << "-1\n";
    return 0;
}