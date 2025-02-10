#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

int N, M;
vector<vector<int>> board;     // 0: empty, 1: wall
vector<vector<int>> component; // component id
unordered_map<int, int> componentSize;
int componentId = 1;

vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void bfs(int x, int y)
{ // find component
    queue<pair<int, int>> q;
    q.push({x, y});
    component[x][y] = componentId;
    int size = 0;

    while (!q.empty())
    {
        int cx = q.front().first, cy = q.front().second;
        q.pop();
        size++;

        for (auto dir : directions)
        {
            int nx = cx + dir.first, ny = cy + dir.second;
            if (nx >= 0 && ny >= 0 && nx < N && ny < M && board[nx][ny] == 0 && component[nx][ny] == 0)
            { // board[nx][ny] == 0인 경우(componentId로 그룹)
                component[nx][ny] = componentId;
                q.push({nx, ny});
            }
        }
    }

    componentSize[componentId] = size; // 그룹의 크기 저장
    componentId++;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    board.resize(N, vector<int>(M));
    component.resize(N, vector<int>(M, 0));

    for (int i = 0; i < N; i++)
    { // input
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            board[i][j] = row[j] - '0';
        }
    }

    for (int i = 0; i < N; i++)
    { // find component
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 0 && component[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }

    vector<vector<int>> result(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 1)
            {
                unordered_map<int, bool> seen;
                int reachable = 1; // 기본 1
                for (auto dir : directions)
                {
                    int nx = i + dir.first, ny = j + dir.second;
                    if (nx >= 0 && ny >= 0 && nx < N && ny < M && board[nx][ny] == 0)
                    { // board[nx][ny] == 0인 경우
                        int compId = component[nx][ny];
                        if (!seen[compId])
                        { // 그룹을 더해줌(이때 중복 방지)
                            reachable += componentSize[compId];
                            seen[compId] = true;
                        }
                    }
                }
                result[i][j] = reachable % 10;
            }
        }
    }

    for (int i = 0; i < N; i++)
    { // output
        for (int j = 0; j < M; j++)
        {
            cout << result[i][j];
        }
        cout << "\n";
    }
}