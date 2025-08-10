#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int I;
        cin >> I;

        vector<vector<int>> board(I, vector<int>(I, 0));

        pair<int, int> start, end;
        cin >> start.first >> start.second >> end.first >> end.second;

        queue<pair<int, int>> q;
        q.push(start);
        board[start.first][start.second] = 1;
        while (!q.empty())
        {
            pair<int, int> curr = q.front();
            q.pop();

            if (curr == end)
            {
                cout << board[curr.first][curr.second] - 1 << '\n';
            }

            int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
            int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

            for (int i = 0; i < 8; i++)
            {
                int nx = curr.first + dx[i];
                int ny = curr.second + dy[i];
                if (nx >= 0 && nx < I && ny >= 0 && ny < I && board[nx][ny] == 0)
                { // 범위 체크 및 방문 여부 확인
                    q.push({nx, ny});
                    board[nx][ny] = board[curr.first][curr.second] + 1;
                }
            }
        }
    }
}