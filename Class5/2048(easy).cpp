#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
보드 이동 구현
5번 이동 : backtracking을 이용한 완전탐색

*/

int N;
vector<vector<int>> board;

void move(vector<vector<int>> &b, int dir)
{
    if (dir == 0)
    { // up
        for (int j = 0; j < N; j++)
        {
            int idx = 0;
            for (int i = 1; i < N; i++)
            {
                if (b[i][j] == 0)
                    continue;
                int temp = b[i][j];
                b[i][j] = 0;
                if (b[idx][j] == 0)
                { // 빈칸이면
                    b[idx][j] = temp;
                }
                else if (b[idx][j] == temp)
                { // 같은 숫자면
                    b[idx][j] *= 2;
                    idx++;
                }
                else
                { // 다른 숫자면
                    b[++idx][j] = temp;
                }
            }
        }
    }
    else if (dir == 1)
    { // down
        for (int j = 0; j < N; j++)
        {
            int idx = N - 1;
            for (int i = N - 2; i >= 0; i--)
            {
                if (b[i][j] == 0)
                    continue;
                int temp = b[i][j];
                b[i][j] = 0;
                if (b[idx][j] == 0)
                { // 빈칸이면
                    b[idx][j] = temp;
                }
                else if (b[idx][j] == temp)
                { // 같은 숫자면
                    b[idx][j] *= 2;
                    idx--;
                }
                else
                { // 다른 숫자면
                    b[--idx][j] = temp;
                }
            }
        }
    }
    else if (dir == 2)
    { // left
        for (int i = 0; i < N; i++)
        {
            int idx = 0;
            for (int j = 1; j < N; j++)
            {
                if (b[i][j] == 0)
                    continue;
                int temp = b[i][j];
                b[i][j] = 0;
                if (b[i][idx] == 0)
                { // 빈칸이면
                    b[i][idx] = temp;
                }
                else if (b[i][idx] == temp)
                { // 같은 숫자면
                    b[i][idx] *= 2;
                    idx++;
                }
                else
                { // 다른 숫자면
                    b[i][++idx] = temp;
                }
            }
        }
    }
    else if (dir == 3)
    { // right
        for (int i = 0; i < N; i++)
        {
            int idx = N - 1;
            for (int j = N - 2; j >= 0; j--)
            {
                if (b[i][j] == 0)
                    continue;
                int temp = b[i][j];
                b[i][j] = 0;
                if (b[i][idx] == 0)
                { // 빈칸이면
                    b[i][idx] = temp;
                }
                else if (b[i][idx] == temp)
                { // 같은 숫자면
                    b[i][idx] *= 2;
                    idx--;
                }
                else
                { // 다른 숫자면
                    b[i][--idx] = temp;
                }
            }
        }
    }
}

int getMaxValue(const vector<vector<int>> &b)
{
    int maxValue = 0;
    for (const auto &row : b)
    {
        for (int val : row)
        {
            maxValue = max(maxValue, val);
        }
    }
    return maxValue;
}

int dfs(vector<vector<int>> b, int depth)
{
    if (depth == 5)
    { // 5번 이동했으면
        return getMaxValue(b);
    }
    int maxValue = 0;
    for (int dir = 0; dir < 4; dir++)
    {
        vector<vector<int>> newBoard = b;
        move(newBoard, dir);
        maxValue = max(maxValue, dfs(newBoard, depth + 1)); // 재귀
    }
    return maxValue;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    board.resize(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> board[i][j];
        }
    }

    cout << dfs(board, 0);
    return 0;
}