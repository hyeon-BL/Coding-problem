#include <iostream>
#include <vector>
using namespace std;

int cnt_neg = 0, cnt_zero = 0, cnt_pos = 0;
vector<vector<int>> matrix;

void count_elements(int x, int y, int size)
{
    if (size == 1)
    {
        if (matrix[x][y] < 0)
            cnt_neg++;
        else if (matrix[x][y] == 0)
            cnt_zero++;
        else
            cnt_pos++;
        return;
    }

    int first_value = matrix[x][y];
    bool is_uniform = true;

    for (int i = x; i < x + size; i++)
    {
        for (int j = y; j < y + size; j++)
        {
            if (matrix[i][j] != first_value)
            {
                is_uniform = false;
                break;
            }
        }
        if (!is_uniform)
            break;
    }

    if (is_uniform)
    {
        if (first_value < 0)
            cnt_neg++;
        else if (first_value == 0)
            cnt_zero++;
        else
            cnt_pos++;
    }
    else
    {
        int third_size = size / 3;
        count_elements(x, y, third_size);
        count_elements(x, y + third_size, third_size);
        count_elements(x, y + 2 * third_size, third_size);
        count_elements(x + third_size, y, third_size);
        count_elements(x + third_size, y + third_size, third_size);
        count_elements(x + third_size, y + 2 * third_size, third_size);
        count_elements(x + 2 * third_size, y, third_size);
        count_elements(x + 2 * third_size, y + third_size, third_size);
        count_elements(x + 2 * third_size, y + 2 * third_size, third_size);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    matrix.resize(N, vector<int>(N));

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> matrix[i][j];
        }
    }

    // Divide and conquer
    count_elements(0, 0, N);

    cout << cnt_neg << "\n"
         << cnt_zero << "\n"
         << cnt_pos << "\n";
}