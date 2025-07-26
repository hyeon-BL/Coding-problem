#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;

    vector<vector<int>> arr1(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> arr2(N + 1, vector<int>(M + 1, 0));
    vector<vector<char>> WB(N + 1, vector<char>(M + 1, 0));
    vector<vector<char>> BW(N + 1, vector<char>(M + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            WB[i][j] = ((i + j) % 2 == 0) ? 'W' : 'B';
            BW[i][j] = ((i + j) % 2 == 0) ? 'B' : 'W';
        }
    }

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            if (s[j - 1] != WB[i][j])
                arr1[i][j] = 1;
            if (s[j - 1] != BW[i][j])
                arr2[i][j] = 1;
        }
    }
    vector<vector<int>> cum1(N + 1, vector<int>(M + 1, 0));
    vector<vector<int>> cum2(N + 1, vector<int>(M + 1, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cum1[i][j] = arr1[i][j] + cum1[i - 1][j] + cum1[i][j - 1] - cum1[i - 1][j - 1];
            cum2[i][j] = arr2[i][j] + cum2[i - 1][j] + cum2[i][j - 1] - cum2[i - 1][j - 1];
        }
    }

    int maxSum = 0;
    for (int i = K; i <= N; i++)
    {
        for (int j = K; j <= M; j++)
        {
            int sum1 = cum1[i][j] - cum1[i - K][j] - cum1[i][j - K] + cum1[i - K][j - K];
            int sum2 = cum2[i][j] - cum2[i - K][j] - cum2[i][j - K] + cum2[i - K][j - K];
            maxSum = max(maxSum, max(sum1, sum2));
        }
    }
    cout << K * K - maxSum << '\n';
}