#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

// 전역 변수
int R, C;
pair<int, int> moskva;
pair<int, int> zagreb;
vector<string> grid;

// 방문 배열
vector<vector<bool>> visitedM;
vector<vector<bool>> visitedZ;

// 방향: 0:상, 1:하, 2:좌, 3:우
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

/**
 * @brief 해당 파이프가 주어진 방향으로 연결이 가능한지 확인
 * @param pipe 파이프 문자 ('|', '-', '+', '1'...'4', 'M', 'Z')
 * @param dir 방향 (0:상, 1:하, 2:좌, 3:우)
 * @return 연결 가능하면 true
 */
bool connects(char pipe, int dir)
{
    if (pipe == '.' || pipe == '*')
        return false;
    if (pipe == 'M' || pipe == 'Z')
        return true;

    switch (dir)
    {
    case 0: // 상
        return (pipe == '|' || pipe == '+' || pipe == '2' || pipe == '3');
    case 1: // 하
        return (pipe == '|' || pipe == '+' || pipe == '1' || pipe == '4');
    case 2: // 좌
        return (pipe == '-' || pipe == '+' || pipe == '3' || pipe == '4');
    case 3: // 우
        return (pipe == '-' || pipe == '+' || pipe == '1' || pipe == '2');
    }
    return false;
}

/**
 * @brief 주어진 방향의 반대 방향을 반환
 */
int oppositeDir(int dir)
{
    // 0(상) <-> 1(하), 2(좌) <-> 3(우)
    return dir ^ 1;
}

/**
 * @brief BFS를 수행하여 연결된 네트워크를 탐색
 * @param start 시작 위치
 * @param visited 방문 배열 (참조로 전달)
 */
void bfs(pair<int, int> start, vector<vector<bool>> &visited)
{
    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    while (!q.empty())
    {
        pair<int, int> cur = q.front();
        q.pop();

        char curPipe = grid[cur.first][cur.second];

        for (int i = 0; i < 4; ++i)
        {
            // 현재 파이프가 i 방향으로 연결되는지 확인
            if (!connects(curPipe, i))
                continue;

            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            // 1. 범위 체크
            if (nx < 0 || nx >= R || ny < 0 || ny >= C)
                continue;
            // 2. 이미 방문한 곳 체크
            if (visited[nx][ny])
                continue;

            char nextPipe = grid[nx][ny];

            // 3. 다음 파이프가 반대 방향으로 연결되는지 확인
            if (connects(nextPipe, oppositeDir(i)))
            {
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

/**
 * @brief 4방향의 연결 필요 여부에 따라 파이프 문자를 반환
 */
char getPipeType(bool needs[4])
{
    if (needs[0] && needs[1] && needs[2] && needs[3])
        return '+';
    if (needs[0] && needs[1])
        return '|';
    if (needs[2] && needs[3])
        return '-';
    if (needs[1] && needs[3])
        return '1'; // 하, 우
    if (needs[0] && needs[3])
        return '2'; // 상, 우
    if (needs[0] && needs[2])
        return '3'; // 상, 좌
    if (needs[1] && needs[2])
        return '4'; // 하, 좌

    // 이 경우는 문제 조건상 발생하지 않아야 함
    return '?';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    grid.resize(R);
    visitedM.assign(R, vector<bool>(C, false));
    visitedZ.assign(R, vector<bool>(C, false));

    for (int i = 0; i < R; ++i)
    {
        cin >> grid[i];
        for (int j = 0; j < C; ++j)
        {
            if (grid[i][j] == 'M')
                moskva = {i, j};
            else if (grid[i][j] == 'Z')
                zagreb = {i, j};
        }
    }

    // 1. M과 Z에서 각각 BFS 실행 (Z는 M에서 도달 불가능해야 함)
    bfs(moskva, visitedM);
    if (!visitedM[zagreb.first][zagreb.second])
    {
        bfs(zagreb, visitedZ);
    }

    // 2. 유실 지점 '.' 탐색
    for (int r = 0; r < R; ++r)
    {
        for (int c = 0; c < C; ++c)
        {
            if (grid[r][c] == '.')
            {
                bool needs[4] = {false, false, false, false}; // 상, 하, 좌, 우
                bool hasM = false;
                bool hasZ = false;

                // 3. 4방향 인접 칸 검사
                for (int i = 0; i < 4; ++i)
                {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if (nr < 0 || nr >= R || nc < 0 || nc >= C)
                        continue;

                    char neighborPipe = grid[nr][nc];

                    // 인접 칸이 반대 방향으로 연결되는지 확인
                    if (!connects(neighborPipe, oppositeDir(i)))
                        continue;

                    // M 네트워크에 속하는지 확인
                    if ((visitedM[nr][nc] || visitedZ[moskva.first][moskva.second]) && !(nr == moskva.first && nc == moskva.second))
                    {
                        needs[i] = true;
                        hasM = true;
                    }
                    // Z 네트워크에 속하는지 확인
                    if ((visitedZ[nr][nc] || visitedM[zagreb.first][zagreb.second]) && !(nr == zagreb.first && nc == zagreb.second))
                    {
                        needs[i] = true;
                        hasZ = true;
                    }
                }

                // 4. M과 Z 네트워크 모두에 연결된다면 이 칸이 정답
                if (hasM && hasZ)
                {
                    cout << r + 1 << " " << c + 1 << " " << getPipeType(needs) << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}
