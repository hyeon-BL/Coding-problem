#include <iostream>
#include <vector>
#include <string> // vector<char> 대신 string 사용이 편리
#include <queue>

using namespace std;

int R, C;
vector<string> lake; // string 벡터 사용
vector<pair<int, int>> swans;
bool visited[1500][1500]; // 백조의 방문 여부를 기록 (재방문 방지)

// 1. BFS를 위한 큐(Queue) 선언
queue<pair<int, int>> swanQ;     // 백조가 헤엄칠 수 있는 영역
queue<pair<int, int>> waterQ;    // 물이 녹을 영역
queue<pair<int, int>> nextSwanQ; // 다음 날 백조가 탐색을 시작할 영역 (얼음이었던 곳)

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 백조가 만날 수 있는지 확인하고, 다음 날 탐색할 지점을 찾는 함수
bool findSwans()
{
    while (!swanQ.empty())
    {
        pair<int, int> curr = swanQ.front();
        swanQ.pop();

        // 다른 백조를 만났다면 성공
        if (curr.first == swans[1].first && curr.second == swans[1].second)
        {
            return true;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny])
                continue;

            visited[nx][ny] = true;

            // 다음 위치가 얼음('X')이면, 지금은 못 가지만 다음 날엔 녹을 수 있으므로 nextSwanQ에 추가
            if (lake[nx][ny] == 'X')
            {
                nextSwanQ.push({nx, ny});
            }
            // 다음 위치가 물('.')이면, 오늘 바로 갈 수 있으므로 swanQ에 추가하여 탐색 계속
            else
            {
                swanQ.push({nx, ny});
            }
        }
    }
    return false;
}

// 하루 동안 물에 인접한 얼음을 녹이는 함수
void meltIce()
{
    int q_size = waterQ.size(); // 이번 날에 녹일 얼음의 기준이 되는 현재 물의 영역만큼만 반복(새로 추가된 물은 다음 날 녹일 얼음의 기준이 됨)
    for (int i = 0; i < q_size; ++i)
    {
        pair<int, int> curr = waterQ.front();
        waterQ.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;

            // 인접한 곳이 얼음이면 물로 바꾸고, 다음 날 녹일 기준점이 되므로 waterQ에 추가
            if (lake[nx][ny] == 'X')
            {
                lake[nx][ny] = '.';
                waterQ.push({nx, ny});
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    lake.resize(R);

    // 초기 상태 설정
    for (int i = 0; i < R; i++)
    {
        cin >> lake[i];
        for (int j = 0; j < C; j++)
        {
            if (lake[i][j] == 'L')
            {
                swans.push_back({i, j});
                waterQ.push({i, j}); // 백조 위치도 물이므로 waterQ에 추가
            }
            else if (lake[i][j] == '.')
            {
                waterQ.push({i, j}); // 초기 물 위치를 모두 waterQ에 추가
            }
        }
    }

    swanQ.push(swans[0]); // 첫 번째 백조 위치에서 탐색 시작
    visited[swans[0].first][swans[0].second] = true;

    int days = 0;
    while (true)
    {
        // 1. 백조가 만날 수 있는지 확인
        if (findSwans())
        {
            cout << days;
            break;
        }

        // 2. 하루 동안 얼음을 녹임
        meltIce();

        // 3. 다음 날 탐색을 위해 큐를 교체
        swanQ = nextSwanQ;
        // nextSwanQ는 비워줌 (queue<pair<int, int>>()로 빈 큐를 할당)
        nextSwanQ = queue<pair<int, int>>();

        // 4. 날짜 증가
        days++;
    }

    return 0;
}

/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<char>> lake;
vector<pair<int, int>> swans;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void DayByDay()
{
    int R = lake.size();
    int C = lake[0].size();
    vector<pair<int, int>> melts;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (lake[i][j] == 'X')
            {
                for (int dir = 0; dir < 4; dir++)
                {
                    int ni = i + dx[dir];
                    int nj = j + dy[dir];
                    if (find(melts.begin(), melts.end(), make_pair(ni, nj)) != melts.end())
                    { // when already melted this day
                        break;
                    }
                    if (ni >= 0 && ni < R && nj >= 0 && nj < C && lake[ni][nj] == '.')
                    {
                        lake[i][j] = '.';
                        melts.push_back({i, j});
                        break;
                    }
                }
            }
        }
    }
}

void DFS(int x, int y, vector<vector<bool>> &visited)
{
    int R = lake.size();
    int C = lake[0].size();
    visited[x][y] = true;

    for (int dir = 0; dir < 4; dir++)
    {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (nx >= 0 && nx < R && ny >= 0 && ny < C && !visited[nx][ny] && lake[nx][ny] != 'X')
        {
            DFS(nx, ny, visited);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int R, C;
    cin >> R >> C;
    lake.resize(R, vector<char>(C));
    for (int i = 0; i < R; i++)
    {
        string row;
        cin >> row;

        for (int j = 0; j < C; j++)
        {
            lake[i][j] = row[j];
            if (row[j] == 'L')
            {
                swans.push_back({i, j});
            }
        }
    }

    int days = 0;
    while (true)
    {
        vector<vector<bool>> visited(R, vector<bool>(C, false));
        DFS(swans[0].first, swans[0].second, visited);
        if (visited[swans[1].first][swans[1].second])
        {
            cout << days;
            break;
        }

        DayByDay();
        days++;
    }
}
*/