#include <iostream>
#include <vector>
#include <stack>
#include <climits>
using namespace std;

char board[5][5];
vector<pair<int, int>> pieces; // 조각의 위치 저장
int min_moves = INT_MAX;       // 최소 이동 횟수

// 방향 벡터 (상, 하, 좌, 우)
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// DFS를 통해 연결된 조각인지 확인
bool isConnected()
{
    int c = 0;
    vector<vector<bool>> visit(5, vector<bool>(5, false));

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (board[i][j] == '*' && !visit[i][j])
            {
                visit[i][j] = true;
                ++c;
                stack<pair<int, int>> stk;
                stk.push({i, j});

                while (!stk.empty())
                { // DFS 탐색
                    int x = stk.top().first;
                    int y = stk.top().second;
                    stk.pop();

                    for (int dir = 0; dir < 4; ++dir)
                    {
                        int nx = x + dx[dir];
                        int ny = y + dy[dir];

                        if (nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && !visit[nx][ny] && board[nx][ny] == '*')
                        {
                            visit[nx][ny] = true;
                            stk.push({nx, ny});
                        }
                    }
                }
            }
        }
    }

    return c == 1; // 모두 연결되어 있어야 c == 1, 아니면 c > 1
}

// 조각이 있을 수 있는 모든 경우 탐색
void DFS(int c, int d)
{
    if (d >= min_moves)
    {
        return;
    }

    if (c == pieces.size())
    { // 모든 조각을 배치한 경우
        if (isConnected())
        { // 조각이 연결되어 있는지 확인
            min_moves = min(min_moves, d);
        }
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (board[i][j] == '.')
            {
                board[i][j] = '*';
                DFS(c + 1, d + abs(pieces[c].first - i) + abs(pieces[c].second - j));
                board[i][j] = '.';
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 5; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < 5; j++)
        {
            board[i][j] = s[j];
            if (board[i][j] == '*')
                pieces.push_back({i, j});
            board[i][j] = '.'; // 초기화
        }
    }

    DFS(0, 0);

    cout << min_moves << '\n';
    return 0;
}