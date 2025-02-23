#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<int>> chess;
vector<bool> d1, d2; // diagonals
int max_bishops;

void backtrack(int row, int col, int count)
{
    if (col >= N)
    { // 다음 행으로 이동
        row++;
        col = (col % 2 == 0) ? 1 : 0;
    }
    if (row >= N)
    { // 종료 조건
        max_bishops = max(max_bishops, count);
        return;
    }

    if (chess[row][col] == 1 && !d1[row + col] && !d2[row - col + N - 1])
    { // 비숍을 놓을 수 있는 경우
        d1[row + col] = d2[row - col + N - 1] = true;
        backtrack(row, col + 2, count + 1); // 다음 경우 호출
        d1[row + col] = d2[row - col + N - 1] = false;
    }
    backtrack(row, col + 2, count);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    chess.resize(N, vector<int>(N));
    d1.resize(2 * N - 1, false);
    d2.resize(2 * N - 1, false);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> chess[i][j];
        }
    }

    max_bishops = 0;
    backtrack(0, 0, 0); // 짝수 열부터 시작
    int max_bishops_even = max_bishops;

    max_bishops = 0;
    backtrack(0, 1, 0); // 홀수 열부터 시작
    int max_bishops_odd = max_bishops;

    cout << max_bishops_even + max_bishops_odd;
    return 0;
}