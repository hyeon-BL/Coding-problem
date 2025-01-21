#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct House
{
    int r, g, b;
};

int main()
{
    int N;
    cin >> N;
    vector<House> houses(N);
    for (int i = 0; i < N; i++)
    {
        cin >> houses[i].r >> houses[i].g >> houses[i].b;
    }

    const int INF = 1e9;
    int result = INF;

    // the first house to be red
    vector<vector<int>> dp(N, vector<int>(3, INF));
    dp[0][0] = houses[0].r;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i].r;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i].g;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i].b;
    }
    result = min(result, min(dp[N - 1][1], dp[N - 1][2])); // Last house cannot be red

    // the first house to be green
    dp.assign(N, vector<int>(3, INF));
    dp[0][1] = houses[0].g;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i].r;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i].g;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i].b;
    }
    result = min(result, min(dp[N - 1][0], dp[N - 1][2])); // Last house cannot be green

    // the first house to be blue
    dp.assign(N, vector<int>(3, INF));
    dp[0][2] = houses[0].b;
    for (int i = 1; i < N; i++)
    {
        dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + houses[i].r;
        dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + houses[i].g;
        dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + houses[i].b;
    }
    result = min(result, min(dp[N - 1][0], dp[N - 1][1])); // Last house cannot be blue

    cout << result;

    return 0;
}