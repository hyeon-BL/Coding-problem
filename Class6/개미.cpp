#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
sparse_table[i][j] : i번째 부모 노드, 부모 노드까지의 에너지 소모량
reference : https://velog.io/@rootachieve/%EB%B0%B1%EC%A4%80-14942-%EA%B0%9C%EB%AF%B8


*/

pair<long long, long long> sparse_table[17][100001]; // sparse_table[i][j] : i번째 부모 노드, 부모 노드까지의 에너지 소모량
bool visited[100001];                                // 방문 여부

void dfs(int node, vector<vector<pair<int, int>>> &adjacency)
{
    visited[node] = true;
    for (int i = 0; i < adjacency[node].size(); i++)
    {
        int next_node = adjacency[node][i].first;
        int energy = adjacency[node][i].second;
        if (!visited[next_node])
        {
            sparse_table[0][next_node] = {node, energy};
            dfs(next_node, adjacency);
        }
    }
}

void make_sparse_table(int n)
{
    for (int i = 1; i < 17; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (sparse_table[i - 1][j].first != -1)
            {
                int parent = sparse_table[i - 1][j].first;
                sparse_table[i][j].first = sparse_table[i - 1][parent].first;
                sparse_table[i][j].second = sparse_table[i - 1][j].second + sparse_table[i - 1][parent].second;
            }
        }
    }
}

int closest_node(int target, int energy)
{
    for (int i = 16; i >= 0; i--)
    {
        if (sparse_table[i][target].first != 0 && sparse_table[i][target].second <= energy)
        {
            energy -= sparse_table[i][target].second;
            target = sparse_table[i][target].first;
        }
    }
    return target;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; // 방의 개수
    cin >> n;
    vector<int> energy(n + 1);                       // 각각의 개미가 보유한 에너지
    vector<vector<pair<int, int>>> adjacency(n + 1); // 인접 리스트

    for (int i = 1; i <= n; i++)
    {
        cin >> energy[i]; // 각각의 개미가 보유한 에너지
    }
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c; // 방 번호, 연결된 방 번호, 에너지 소모량
        adjacency[a].push_back({b, c});
        adjacency[b].push_back({a, c});
    }
    dfs(1, adjacency);    // DFS를 통해 부모 노드와 에너지 소모량을 구함
    make_sparse_table(n); // sparse table 생성

    for (int i = 1; i <= n; i++)
    {
        int target = closest_node(i, energy[i]); // 에너지를 소모하여 도달할 수 있는 방
        cout << target << "\n";                  // 방 번호 출력
    }
}