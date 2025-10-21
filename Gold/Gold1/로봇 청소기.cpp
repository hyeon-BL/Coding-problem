#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct State {
    int x, y;
    int mask;   // bitmask of cleaned dirt
    int moves;
};

vector<string> board;
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int bfs(int start_x, int start_y, const vector<vector<int>>& dirtId, int total_trash) {
    int h = board.size();
    int w = board[0].size();
    if (total_trash == 0) return 0;
    int target = (1 << total_trash) - 1;
    vector<vector<vector<char>>> visited(h, vector<vector<char>>(w, vector<char>(1 << total_trash, 0)));
    
    queue<State> q;
    q.push({start_x, start_y, 0, 0});
    visited[start_x][start_y][0] = 1;

    while (!q.empty()) {
        State cur = q.front(); q.pop();
        if (cur.mask == target) return cur.moves;

        for (int dir = 0; dir < 4; ++dir) {
            int nx = cur.x + dx[dir];
            int ny = cur.y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= h || ny >= w) continue;
            if (board[nx][ny] == 'x') continue;

            int new_mask = cur.mask;
            int id = dirtId[nx][ny];
            if (id != -1) new_mask |= (1 << id);

            if (!visited[nx][ny][new_mask]) {
                visited[nx][ny][new_mask] = 1;
                q.push({nx, ny, new_mask, cur.moves + 1});
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        board.assign(h, "");
        int start_x = -1, start_y = -1;
        vector<pair<int,int>> dirtPos;
        vector<vector<int>> dirtId(h, vector<int>(w, -1));

        for (int i = 0; i < h; ++i) {
            cin >> board[i];
            for (int j = 0; j < w; ++j) {
                if (board[i][j] == 'o') {
                    start_x = i; start_y = j;
                } else if (board[i][j] == '*') {
                    int id = dirtPos.size();
                    dirtPos.emplace_back(i, j);
                    dirtId[i][j] = id;
                }
            }
        }

        int total_trash = dirtPos.size();
        int result = bfs(start_x, start_y, dirtId, total_trash);
        cout << result << '\n';

        dirtPos.clear();
        board.clear();
        dirtId.clear();
    }

    return 0;
}