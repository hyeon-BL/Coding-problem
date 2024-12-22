#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(N));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
        }
    }
    vector<vector<int>> desired(M, vector<int>(4));
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> desired[i][j];
        }
    }
    vector<vector<int>> cumsum(N + 1, vector<int>(N + 1));
    for (int i = 1; i <= N; i++)
    { // O(N^2) : 2차원 배열의 누적합 구하기
        for (int j = 1; j <= N; j++)
        {
            cumsum[i][j] = cumsum[i - 1][j] + cumsum[i][j - 1] - cumsum[i - 1][j - 1] + v[i - 1][j - 1];
        }
    }
    for (int i = 0; i < M; i++)
    { // O(M)
        int x1 = desired[i][0] - 1;
        int y1 = desired[i][1] - 1;
        int x2 = desired[i][2];
        int y2 = desired[i][3];
        cout << cumsum[x2][y2] - cumsum[x1][y2] - cumsum[x2][y1] + cumsum[x1][y1] << '\n';
    }
}

/* unefficient solution (time complexity: O(N^2 * M))
    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        for (int j = desired[i][0] - 1; j < desired[i][2]; j++)
        { // desired[i][0] ~ desired[i][2] 행
            for (int k = desired[i][1] - 1; k < desired[i][3]; k++)
            { // desired[i][1] ~ desired[i][3] 열
                sum += v[j][k];
            }
        }
        cout << sum << '\n';
    }
*/