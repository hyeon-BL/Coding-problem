#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<pair<int, int>> matrix(N);
    for (int i = 0; i < N; i++)
    {
        cin >> matrix[i].first >> matrix[i].second;
    }

    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 1; i < N; i++)
    { // i는 행렬의 개수 - 1 (곱 연산을 수행하는 횟수)
        for (int j = 0; j < N - i; j++)
        { // j부터 j+i까지의 행렬을 곱하는 경우
            int k = i + j;
            dp[j][k] = 2e9;
            for (int l = j; l < k; l++)
            { // dp[j][k]는 j부터 k까지의 행렬을 곱했을 때의 최소 곱셈 연산 횟수
                dp[j][k] = min(dp[j][k], dp[j][l] + dp[l + 1][k] + matrix[j].first * matrix[l].second * matrix[k].second);
            }
        }
    }

    cout << dp[0][N - 1];
}

/*
3
5 3
3 2
2 6
답 : 90

dp[i][j] = i부터 j까지의 행렬을 곱했을 때의 최소 곱셈 연산 횟수

 0 30 90
 0  0 36
 0  0  0

dp[0][1] = dp[0][0] + dp[1][1] + 5 * 3 * 2 = 0 + 0 + 30 = 30
dp[0][2] = dp[0][0] + dp[1][2] + 5 * 3 * 6 = 0 + 36 + 90 = 126
dp[0][2] = dp[0][1] + dp[2][2] + 5 * 2 * 6 = 30 + 0 + 60 = 90
dp[1][2] = dp[1][1] + dp[2][2] + 3 * 2 * 6 = 0 + 0 + 36 = 36
*/