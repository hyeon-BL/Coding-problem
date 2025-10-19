#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int h, w;
vector<string> board;      // 전체 감옥 정보
vector<vector<int>> dist1; // 죄수1에서 (i, j)까지 가는 데 열어야 하는 문 개수
vector<vector<int>> dist2; // 죄수2에서 (i, j)까지 가는 데 열어야 하는 문 개수
vector<vector<int>> dist0; // 외부 (0, 0)에서 (i, j)까지 가는 데 열어야 하는 문 개수

int dh[4] = {-1, 1, 0, 0};
int dw[4] = {0, 0, -1, 1};

void bfs(int start_h, int start_w, vector<vector<int>> &dist)
{
    deque<pair<int, int>> dq;
    dq.push_back({start_h, start_w});
    dist[start_h][start_w] = 0;

    while (!dq.empty())
    {
        int cur_h = dq.front().first;
        int cur_w = dq.front().second;
        dq.pop_front();

        for (int dir = 0; dir < 4; dir++)
        {
            int next_h = cur_h + dh[dir];
            int next_w = cur_w + dw[dir];

            // 감옥 범위를 벗어나는 경우 무시
            if (next_h < 0 || next_h >= h + 2 || next_w < 0 || next_w >= w + 2)
                continue;
            // 벽인 경우 무시
            if (board[next_h][next_w] == '*')
                continue;
            // 아직 방문하지 않은 칸인 경우
            if (dist[next_h][next_w] == -1)
            {
                // 빈 칸인 경우
                if (board[next_h][next_w] == '.' || board[next_h][next_w] == '$')
                { // cost = 0
                    dist[next_h][next_w] = dist[cur_h][cur_w];
                    dq.push_front({next_h, next_w}); // -> 먼저 탐색하도록 덱의 앞에 삽입
                }
                // 문인 경우
                else if (board[next_h][next_w] == '#')
                { // cost = 1
                    dist[next_h][next_w] = dist[cur_h][cur_w] + 1;
                    dq.push_back({next_h, next_w}); // -> 나중에 탐색하도록 덱의 뒤에 삽입
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> h >> w;
        board.assign(h + 2, string(w + 2, '.')); // 감옥 외부를 '.'로 채운다
        dist1.assign(h + 2, vector<int>(w + 2, -1));
        dist2.assign(h + 2, vector<int>(w + 2, -1));
        dist0.assign(h + 2, vector<int>(w + 2, -1));

        pair<int, int> prisoner1, prisoner2;
        for (int i = 1; i <= h; i++)
        {
            string row;
            cin >> row;
            for (int j = 1; j <= w; j++)
            {
                board[i][j] = row[j - 1];
                if (board[i][j] == '$')
                {
                    if (prisoner1 == make_pair(0, 0))
                        prisoner1 = {i, j};
                    else
                        prisoner2 = {i, j};
                }
            }
        }

        // 각 출발지점에서 BFS 수행
        bfs(0, 0, dist0);
        bfs(prisoner1.first, prisoner1.second, dist1);
        bfs(prisoner2.first, prisoner2.second, dist2);

        int answer = 1e9;

        for (int i = 0; i < h + 2; i++)
        {
            for (int j = 0; j < w + 2; j++)
            {
                // (i, j) 칸으로 세 명이 모두 도달할 수 없는 경우 무시
                if (dist0[i][j] == -1 || dist1[i][j] == -1 || dist2[i][j] == -1)
                    continue;

                // 세 명이 (i, j) 칸으로 이동하기 위해 열어야 하는 문의 개수 계산
                int cnt = dist0[i][j] + dist1[i][j] + dist2[i][j];
                // (i, j) 칸이 문인 경우, 세 명이 한 번씩 중복해서 센 것이므로 2개 빼기
                if (board[i][j] == '#')
                    cnt -= 2;

                answer = min(answer, cnt);
            }
        }
        cout << answer << '\n';
    }
}