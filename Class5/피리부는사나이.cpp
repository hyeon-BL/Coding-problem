#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    char direction;
    int x, y;
    Node *next;
};

void dfs(int x, int y, vector<vector<Node>> &graph, vector<vector<bool>> *visited, vector<vector<bool>> &inPath, bool &hasCycle)
{ // DFS로 사이클 탐색
    (*visited)[x][y] = true;
    inPath[x][y] = true;
    Node **next = &graph[x][y].next;
    if (next)
    {
        int nx = (*next)->x;
        int ny = (*next)->y;
        if (!(*visited)[nx][ny])
        {
            dfs(nx, ny, graph, visited, inPath, hasCycle);
        }
        else if (inPath[nx][ny])
        { // 2번 방문한 경우 사이클이 존재
            hasCycle = true;
        }
    }
    inPath[x][y] = false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 행의 개수, M: 열의 개수
    cin >> N >> M;
    vector<vector<char>> matrix(N, vector<char>(M));
    vector<vector<Node>> graph(N, vector<Node>(M));
    string row;
    for (int i = 0; i < N; i++)
    {
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = row[j];
            graph[i][j] = {row[j], i, j, nullptr};
        }
    }

    // Node에 다음 노드를 저장하여 그래프 생성
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrix[i][j] == 'U' && i > 0)
                graph[i][j].next = &graph[i - 1][j];
            if (matrix[i][j] == 'D' && i < N - 1)
                graph[i][j].next = &graph[i + 1][j];
            if (matrix[i][j] == 'L' && j > 0)
                graph[i][j].next = &graph[i][j - 1];
            if (matrix[i][j] == 'R' && j < M - 1)
                graph[i][j].next = &graph[i][j + 1];
        }
    }

    // 사이클 탐색
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<bool>> inPath(N, vector<bool>(M, false));
    bool hasCycle = false;
    int cycleCount = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (!visited[i][j])
            {
                hasCycle = false;
                dfs(i, j, graph, &visited, inPath, hasCycle);
                if (hasCycle)
                {
                    cycleCount++;
                }
            }
        }
    }

    cout << cycleCount;

    return 0;
}