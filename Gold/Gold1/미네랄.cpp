#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int R, C;
vector<string> cave;
bool visited[100][100];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

// 1. Queue 선언
queue<pair<int, int>> groundQ; // 땅과 연결된 클러스터를 찾기 위한 큐
vector<pair<int, int>> fallQ;  // 떨어질 클러스터를 찾기 위한 벡터

// 2. 함수 정의
void throwStick(int height, bool isLeft)
{ // 막대를 던지는 함수
    int row = R - height;
    if (isLeft)
    { // 창영이가 왼쪽에서 던짐
        for (int col = 0; col < C; col++)
        {
            if (cave[row][col] == 'x')
            {
                cave[row][col] = '.';
                break;
            }
        }
    }
    else
    { // 상근이가 오른쪽에서 던짐
        for (int col = C - 1; col >= 0; col--)
        {
            if (cave[row][col] == 'x')
            {
                cave[row][col] = '.';
                break;
            }
        }
    }
}

void findCluster()
{ // 땅과 연결된 클러스터를 찾고 떨어질 클러스터를 표시하는 함수
    // visited 초기화
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            visited[i][j] = false;

    // groundQ 초기화
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            if (cave[i][j] == 'x' && i == R - 1)
            {
                visited[i][j] = true;
                groundQ.push({i, j});
            }

    while (!groundQ.empty())
    { // 땅과 연결된 클러스터 찾기
        pair<int, int> curr = groundQ.front();
        groundQ.pop();

        for (int dir = 0; dir < 4; dir++)
        {
            int nx = curr.first + dx[dir];
            int ny = curr.second + dy[dir];

            if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny] || cave[nx][ny] == '.')
                continue;

            visited[nx][ny] = true;
            groundQ.push({nx, ny});
        }
    }

    for (int i = 0; i < R; i++)
    { // 떨어질 클러스터 찾기
        for (int j = 0; j < C; j++)
        {
            if (cave[i][j] == 'x' && !visited[i][j])
            {
                cave[i][j] = '.'; // 떨어질 클러스터를 '.'로 표시
                fallQ.push_back({i, j});
            }
        }
    }
}

void dropCluster()
{ // 떨어질 클러스터를 아래로 내리는 함수
    int minDrop = R;
    for (const auto &coord : fallQ)
    {
        int x = coord.first;
        int y = coord.second;
        int drop = 0;
        for (int nx = x + 1; nx < R; nx++)
        {
            if (cave[nx][y] == 'x' && visited[nx][y])
                break; // 땅과 연결된 클러스터에 닿으면 멈춤
            drop++;
        }
        minDrop = min(minDrop, drop);
    }

    for (const auto &coord : fallQ)
    {
        int x = coord.first;
        int y = coord.second;
        cave[x + minDrop][y] = 'x'; // 클러스터를 minDrop만큼 내림
    }
    fallQ.clear(); // 다음 턴을 위해 초기화
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    cave.resize(R);

    for (int i = 0; i < R; i++)
        cin >> cave[i];

    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int height;
        cin >> height;
        throwStick(height, i % 2 == 0);
        findCluster();
        dropCluster();
    }

    for (const auto &row : cave)
        cout << row << '\n';
}