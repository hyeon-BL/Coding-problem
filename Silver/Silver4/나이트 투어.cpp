#include <iostream>
#include <vector>
using namespace std;

bool is_knight_move(const string &from, const string &to)
{
    int from_row = from[0] - 'A';
    int from_col = from[1] - '1';
    int to_row = to[0] - 'A';
    int to_col = to[1] - '1';

    int row_diff = abs(from_row - to_row);
    int col_diff = abs(from_col - to_col);

    return (row_diff == 2 && col_diff == 1) || (row_diff == 1 && col_diff == 2);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<vector<int>> board(6, vector<int>(6, 0));
    string pos, prev_pos, first_pos;
    for (int i = 1; i <= 36; i++)
    {
        cin >> pos;
        board[pos[0] - 'A'][pos[1] - '1'] = 1;
        if (i > 1)
        {
            if (!is_knight_move(prev_pos, pos))
            {
                cout << "Invalid" << '\n';
                return 0;
            }
        }
        if (i == 1)
            first_pos = pos;
        prev_pos = pos;
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            if (board[i][j] == 0 || !is_knight_move(prev_pos, first_pos))
            {
                cout << "Invalid" << '\n';
                return 0;
            }
        }
    }
    cout << "Valid" << '\n';
    return 0;
}