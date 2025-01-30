#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N : 활성화된 앱, M : 필요한 메모리
    cin >> N >> M;
    vector<int> memory(N + 1); // memory[i] = i번 앱이 사용하는 메모리
    vector<int> cost(N + 1);   // cost[i] = i번 앱을 비활성화하는 비용

    for (int i = 1; i <= N; i++)
    {
        cin >> memory[i];
    }
    for (int i = 1; i <= N; i++)
    {
        cin >> cost[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(10001, 0)); // dp[i][j] = i번 앱까지 고려했을 때, j의 비용으로 확보할 수 있는 최대 메모리
    int result = 10000;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 10000; j++)
        { // j의 비용으로 확보할 수 있는 최대 메모리
            if (j < cost[i])
            { // i번 앱을 비활성화할 수 없는 경우
                dp[i][j] = dp[i - 1][j];
            }
            else
            { // i번 앱을 비활성화 or 활성화하는 경우 중 큰 값
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - cost[i]] + memory[i]);
            }
            if (dp[i][j] >= M)
            { // 필요한 메모리를 확보할 수 있는 최소 비용
                result = min(result, j);
            }
        }
    }
    cout << result;
}

/*
5 60
30 10 20 35 40
3 0 3 5 4

답 : 6

 1  2  3  4  5  6  7  8
 0  0  0 30 30 30 30 30
10 10 40 40 40 40 40 40
10 10 40 40 40 60 60 60
10 10 40 40 45 60 60 75
10 10 40 50 50 60 80 80
*/