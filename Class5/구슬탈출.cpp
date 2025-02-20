#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct State
{
    int rx, ry, bx, by, moves;
};

int N, M;
vector<string> board;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

pair<int, int> move(int x, int y, int dx, int dy)
{ // 이동한 좌표 반환
    while (board[x + dx][y + dy] != '#' && board[x][y] != 'O')
    {
        x += dx;
        y += dy;
    }
    return {x, y};
}

int bfs(int rx, int ry, int bx, int by)
{
    queue<State> q;
    q.push({rx, ry, bx, by, 0});
    vector<vector<vector<vector<bool>>>> visited(N, vector<vector<vector<bool>>>(M, vector<vector<bool>>(N, vector<bool>(M, false))));
    visited[rx][ry][bx][by] = true;

    while (!q.empty())
    {
        State cur = q.front();
        q.pop();

        if (cur.moves > 10) // 10번 이상 이동했으면
            return -1;
        if (board[cur.rx][cur.ry] == 'O') // 빨간 구슬이 구멍에 빠지면
            return cur.moves;

        for (int i = 0; i < 4; i++)
        { // 상하좌우 이동
            int nrx = move(cur.rx, cur.ry, dx[i], dy[i]).first;
            int nry = move(cur.rx, cur.ry, dx[i], dy[i]).second;
            int nbx = move(cur.bx, cur.by, dx[i], dy[i]).first;
            int nby = move(cur.bx, cur.by, dx[i], dy[i]).second;

            if (board[nbx][nby] == 'O')
                continue;
            if (nrx == nbx && nry == nby)
            { // 빨간 구슬과 파란 구슬이 같은 칸에 있을 때
                if (abs(nrx - cur.rx) + abs(nry - cur.ry) > abs(nbx - cur.bx) + abs(nby - cur.by))
                { // 이동 거리가 더 긴 구슬을 한 칸 뒤로
                    nrx -= dx[i];
                    nry -= dy[i];
                }
                else
                {
                    nbx -= dx[i];
                    nby -= dy[i];
                }
            }

            if (!visited[nrx][nry][nbx][nby])
            { // 방문하지 않았으면
                visited[nrx][nry][nbx][nby] = true;
                q.push({nrx, nry, nbx, nby, cur.moves + 1});
            }
        }
    }

    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    board.resize(N);
    int rx, ry, bx, by;
    for (int i = 0; i < N; i++)
    {
        cin >> board[i];
        for (int j = 0; j < M; j++)
        {
            if (board[i][j] == 'R')
            {
                rx = i;
                ry = j;
            }
            else if (board[i][j] == 'B')
            {
                bx = i;
                by = j;
            }
        }
    }

    cout << bfs(rx, ry, bx, by);
    return 0;
}