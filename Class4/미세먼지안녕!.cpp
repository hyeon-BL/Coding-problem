#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix;
vector<pair<int, int>> air_cleaner;

vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

vector<vector<int>> spread_dust(vector<vector<int>> &matrix)
{ // 미세먼지 확산
    int R = matrix.size();
    int C = matrix[0].size();
    vector<vector<int>> temp_matrix(R, vector<int>(C));

    for (auto &air_clean : air_cleaner) // 공기청정기 위치 재지정정
    {
        temp_matrix[air_clean.first][air_clean.second] = -1;
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] > 0)
            {
                int spread_amount = matrix[i][j] / 5;
                int spread_count = 0;
                for (auto &dir : directions)
                {
                    int nx = i + dir.first;
                    int ny = j + dir.second;
                    if (nx >= 0 && nx < R && ny >= 0 && ny < C && matrix[nx][ny] != -1)
                    { // 범위 내에 있고 공기청정기가 아닌 경우
                        temp_matrix[nx][ny] += spread_amount;
                        spread_count++;
                    }
                }
                temp_matrix[i][j] += matrix[i][j] - spread_amount * spread_count; // 남은 미세먼지 양
            }
        }
    }
    return temp_matrix;
}

vector<vector<int>> operate_air_cleaner(vector<vector<int>> &matrix)
{ // 공기청정기 작동
    int R = matrix.size();
    int C = matrix[0].size();
    vector<vector<int>> temp_matrix = matrix;

    for (auto &air_clean : air_cleaner) // 공기청정기 위치 재지정
    {
        temp_matrix[air_clean.first][air_clean.second] = -1;
    }

    // 위쪽 공기청정기
    int x = air_cleaner[0].first;
    for (int i = x - 1; i > 0; i--)
    { // 아래쪽으로 이동
        temp_matrix[i][0] = temp_matrix[i - 1][0];
    }
    for (int i = 0; i < C - 1; i++)
    { // 왼쪽으로 이동
        temp_matrix[0][i] = temp_matrix[0][i + 1];
    }
    for (int i = 0; i < x; i++)
    { // 위쪽으로 이동
        temp_matrix[i][C - 1] = temp_matrix[i + 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--)
    { // 오른쪽으로 이동
        temp_matrix[x][i] = temp_matrix[x][i - 1];
    }
    temp_matrix[x][1] = 0; // 공기청정기에서 나오는 바람

    // 아래쪽 공기청정기
    x = air_cleaner[1].first;
    for (int i = x + 1; i < R - 1; i++)
    { // 위쪽으로 이동
        temp_matrix[i][0] = temp_matrix[i + 1][0];
    }
    for (int i = 0; i < C - 1; i++)
    { // 왼쪽으로 이동
        temp_matrix[R - 1][i] = temp_matrix[R - 1][i + 1];
    }
    for (int i = R - 1; i > x; i--)
    { // 아래쪽으로 이동
        temp_matrix[i][C - 1] = temp_matrix[i - 1][C - 1];
    }
    for (int i = C - 1; i > 1; i--)
    { // 오른쪽으로 이동
        temp_matrix[x][i] = temp_matrix[x][i - 1];
    }
    temp_matrix[x][1] = 0; // 공기청정기에서 나오는 바람

    return temp_matrix;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int R, C, T; // R: 행, C: 열, T: 시간
    cin >> R >> C >> T;
    matrix.resize(R, vector<int>(C));
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == -1)
            {
                air_cleaner.push_back({i, j});
            }
        }
    }

    while (T--)
    {
        matrix = spread_dust(matrix);
        matrix = operate_air_cleaner(matrix);
    }

    int answer = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (matrix[i][j] > 0)
            {
                answer += matrix[i][j];
            }
        }
    }
    cout << answer;
}