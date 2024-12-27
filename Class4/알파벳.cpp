#include <iostream>
#include <vector>
using namespace std;

int R, C;
vector<vector<char>> board;
vector<bool> visited;
vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int max_length = 0;

/*
경로를 찾는 문제는 대부분 DFS로 해결할 수 있다.
이 경우는 돌아와야 하므로 backtracking을 사용한다.


dp는 경로를 따라가지 못한다. (개수 세는 문제는 dp로 해결 가능)
*/

void backtrack(int x, int y, int length)
{
    max_length = max(max_length, length);

    for (auto &d : dir)
    {
        int nx = x + d.first;
        int ny = y + d.second;

        if (nx < 0 || nx >= R || ny < 0 || ny >= C)
            continue;

        int curr_char = board[nx][ny] - 'A';
        if (!visited[curr_char])
        {
            visited[curr_char] = true;
            backtrack(nx, ny, length + 1);
            visited[curr_char] = false; // backtrack
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> R >> C;
    board.resize(R, vector<char>(C));
    visited.resize(26, false);

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> board[i][j];
        }
    }

    // Start from (0,0) and mark its character as visited
    visited[board[0][0] - 'A'] = true;
    backtrack(0, 0, 1);

    cout << max_length;
    return 0;
}