#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> sudoku(9, vector<int>(9));
vector<vector<bool>> row_check(9, vector<bool>(9, false));    // row_check[i][j]: i번째 행에 j+1 숫자가 있는지 여부
vector<vector<bool>> col_check(9, vector<bool>(9, false));    // col_check[i][j]: i번째 열에 j+1 숫자가 있는지 여부
vector<vector<bool>> square_check(9, vector<bool>(9, false)); // square_check[i][j]: i번째 사각형에 j+1 숫자가 있는지 여부

bool solve_sudoku(int row, int col)
{
    if (row == 9)
        return true; // Finished
    if (col == 9)
        return solve_sudoku(row + 1, 0); // column 완성 후 다음 row로 이동

    if (sudoku[row][col] != 0)
        return solve_sudoku(row, col + 1); // 숫자가 채워져 있는 경우 스킵킵

    for (int num = 1; num <= 9; num++)
    {
        int square_index = (row / 3) * 3 + col / 3; // 3x3 사각형 인덱스
        if (!row_check[row][num - 1] && !col_check[col][num - 1] && !square_check[square_index][num - 1])
        { // row, col, square 모두 num이 없는 경우
            sudoku[row][col] = num;
            row_check[row][num - 1] = col_check[col][num - 1] = square_check[square_index][num - 1] = true; // num 추가

            if (solve_sudoku(row, col + 1))
                return true; // 다음 column으로 이동

            sudoku[row][col] = 0;
            row_check[row][num - 1] = col_check[col][num - 1] = square_check[square_index][num - 1] = false; // backtracking
        }
    }

    return false; // 1~9까지 모두 시도해봤지만 불가능한 경우
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    for (int i = 0; i < 9; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < 9; j++)
        {
            sudoku[i][j] = row[j] - '0';
            if (sudoku[i][j] != 0)
            { // 숫자가 채워져 있는 경우
                int num = sudoku[i][j] - 1;
                row_check[i][num] = true;
                col_check[j][num] = true;
                square_check[(i / 3) * 3 + (j / 3)][num] = true;
            }
        }
    }

    solve_sudoku(0, 0);

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << sudoku[i][j];
        }
        cout << '\n';
    }

    return 0;
}