#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 도시의 수
    cin >> N;
    vector<vector<int>> city(N, vector<int>(N)); // 도시 간의 거리
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> city[i][j];

            if (city[i][j] == 0)
            { // i번 도시에서 j번 도시로 갈 수 없는 경우
                city[i][j] = INF;
            }
        }
    }

    // dp[mask][i]: 방문한 도시들이 mask일 때, 마지막 방문 도시가 i인 경우의 최소 비용
    vector<vector<int>> dp(1 << N, vector<int>(N, INF));
    dp[1][0] = 0; // 시작점은 0번 도시

    for (int mask = 1; mask < (1 << N); mask++)
    {
        for (int i = 0; i < N; i++)
        {
            if (mask & (1 << i))
            { // i번 도시가 mask에 포함되어 있는 경우
                for (int j = 0; j < N; j++)
                {
                    if (!(mask & (1 << j)))
                    { // j번 도시는 아직 방문하지 않은 경우
                        dp[mask | (1 << j)][j] = min(dp[mask | (1 << j)][j], dp[mask][i] + city[i][j]);
                    }
                }
            }
        }
    }

    // 모든 도시를 방문하고 다시 시작점으로 돌아오는 최소 비용
    int result = INF;
    for (int i = 1; i < N; i++)
    {
        result = min(result, dp[(1 << N) - 1][i] + city[i][0]);
    }

    cout << result;
    return 0;
}