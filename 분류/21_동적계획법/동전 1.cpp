#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    vector<int> dp(k + 1, 0);
    dp[0] = 1; // 0원을 만드는 방법은 1가지 (동전을 사용하지 않는 경우)

    for (int coin : coins)
    { // 각 동전의 가치를 기준으로 DP 배열 업데이트
        for (int j = coin; j <= k; j++)
        { // coin으로 j원을 만드려면 j - coin원을 만드는 방법의 수를 더해야 함
            dp[j] += dp[j - coin];
        }
    }

    cout << dp[k];
}