#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int C, N; // C: 늘려야 할 고객 수, N: 홍보할 수 있는 도시 수
    cin >> C >> N;
    vector<pair<int, int>> cities(N); // (홍보 비용, 고객 수)
    for (int i = 0; i < N; ++i)
    {
        cin >> cities[i].first >> cities[i].second; // 입력: (홍보 비용, 고객 수)
    }

    // DP 테이블 초기화
    vector<int> dp(C + 101, 1e9); // dp[x]: 고객 x명을 늘리기 위한 최소 비용
    dp[0] = 0;                    // 고객 0명을 늘리기 위한 비용은 0

    // DP 테이블 채우기
    for (const auto &city : cities)
    {
        int cost = city.first;       // 홍보 비용
        int customers = city.second; // 고객 수

        for (int x = customers; x <= C + 100; ++x)
        { // 고객수는 최대 C + 100명까지 고려
            dp[x] = min(dp[x], dp[x - customers] + cost);
        }
    }

    // 결과 출력
    int result = *min_element(dp.begin() + C, dp.end());
    cout << result << '\n';

    return 0;
}