#include <iostream>
using namespace std;

#define rows 9
#define cols 9
#define box 3

bool isValid(int sudoku[rows][cols], int row, int col, int num)
{
    // 행에 중복된 숫자가 있는지 확인
    for (int i = 0; i < cols; i++)
    {
        if (sudoku[row][i] == num)
            return false;
    }

    // 열에 중복된 숫자가 있는지 확인
    for (int i = 0; i < rows; i++)
    {
        if (sudoku[i][col] == num)
            return false;
    }

    // 3x3 박스에 중복된 숫자가 있는지 확인
    int boxRowStart = (row / box) * box;
    int boxColStart = (col / box) * box;
    for (int i = boxRowStart; i < boxRowStart + box; i++)
    {
        for (int j = boxColStart; j < boxColStart + box; j++)
        {
            if (sudoku[i][j] == num)
                return false;
        }
    }

    return true;
}

bool solveSudoku(int sudoku[rows][cols])
{
    for (int row = 0; row < rows; row++)
    {
        for (int col = 0; col < cols; col++)
        {
            if (sudoku[row][col] == 0)
            { // 빈 칸에 대해
                for (int num = 1; num <= 9; num++)
                { // 1부터 9까지의 숫자를 시도
                    if (isValid(sudoku, row, col, num))
                    {                           // 숫자가 유효한지 확인
                        sudoku[row][col] = num; // 숫자를 배치

                        if (solveSudoku(sudoku)) // 나머지를 재귀적으로 해결
                            return true;

                        sudoku[row][col] = 0; // 되돌리기
                    }
                }
                return false; // 유효한 숫자가 없으면 false 반환
            }
        }
    }
    return true; // 빈 칸이 없으면 퍼즐이 해결된 것
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int sudoku[rows][cols];
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cin >> sudoku[i][j];
        }
    }

    if (solveSudoku(sudoku))
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                cout << sudoku[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}