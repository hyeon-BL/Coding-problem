#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> input_matrix(vector<vector<int>> &matrix, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            matrix[i][j] = row[j] - '0';
        }
    }
    return matrix;
}

void flip_3x3(vector<vector<int>> &matrix, int x, int y)
{ // 3x3 행렬 뒤집기
    for (int i = x; i < x + 3; i++)
    {
        for (int j = y; j < y + 3; j++)
        {
            matrix[i][j] = 1 - matrix[i][j];
        }
    }
}

bool is_equal(const vector<vector<int>> &matrix_A, const vector<vector<int>> &matrix_B, int N, int M)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (matrix_A[i][j] != matrix_B[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 행, M: 열
    cin >> N >> M;

    vector<vector<int>> matrix_A(N, vector<int>(M));
    vector<vector<int>> matrix_B(N, vector<int>(M));
    matrix_A = input_matrix(matrix_A, N, M);
    matrix_B = input_matrix(matrix_B, N, M);

    int flips = 0;
    for (int i = 0; i <= N - 3; i++)
    {
        for (int j = 0; j <= M - 3; j++)
        {
            if (matrix_A[i][j] != matrix_B[i][j])
            { // 다르면 뒤집기 -> greedy algorithm
                flip_3x3(matrix_A, i, j);
                flips++;
            }
        }
    }

    if (is_equal(matrix_A, matrix_B, N, M))
    {
        cout << flips;
    }
    else
    {
        cout << -1;
    }

    return 0;
}