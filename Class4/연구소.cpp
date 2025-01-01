#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
vector<vector<int>> matrix;
vector<pair<int, int>> empty_spaces;    // 벽을 세울 수 있는 빈 공간(미리 저장 -> time save)
vector<pair<int, int>> virus_positions; // 바이러스 위치
int max_safe_area = 0;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void bfs(vector<vector<int>> &temp_matrix)
{ // 바이러스 퍼뜨리기
    queue<pair<int, int>> q;
    for (auto &virus : virus_positions)
    {
        q.push(virus);
    }

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (auto &dir : directions)
        {
            int nx = x + dir.first;
            int ny = y + dir.second;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && temp_matrix[nx][ny] == 0)
            {
                temp_matrix[nx][ny] = 2;
                q.push({nx, ny});
            }
        }
    }
}

int calculate_safe_area(vector<vector<int>> &temp_matrix)
{
    int safe_area = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (temp_matrix[i][j] == 0)
            {
                safe_area++;
            }
        }
    }
    return safe_area;
}

void place_walls(int count)
{
    if (count == 3)
    {
        vector<vector<int>> temp_matrix = matrix;
        bfs(temp_matrix);
        max_safe_area = max(max_safe_area, calculate_safe_area(temp_matrix));
        return;
    }

    for (auto &space : empty_spaces)
    { // 빈 공간에 벽 세우기
        int x = space.first;
        int y = space.second;
        if (matrix[x][y] == 0)
        {
            matrix[x][y] = 1;
            place_walls(count + 1);
            matrix[x][y] = 0; // 백트래킹
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> N >> M;
    matrix.resize(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 0)
            { // 빈 공간
                empty_spaces.push_back({i, j});
            }
            else if (matrix[i][j] == 2)
            { // 바이러스
                virus_positions.push_back({i, j});
            }
        }
    }

    place_walls(0);

    cout << max_safe_area;

    return 0;
}