#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    vector<int> dp(n + 1);   // dp[i] = i번째 잔까지 온 상황에서 최대로 마실 수 있는 포도주의 양
    dp[1] = arr[1];          // 1번째 잔 -> 무조건 마셔야 최대가 됨
    dp[2] = arr[1] + arr[2]; // 2번째 잔까지는 1번째 잔과 2번째 잔을 모두 마시는 경우가 최대

    for (int i = 3; i <= n; i++)
    {
        dp[i] = arr[i];
        dp[i] = max(dp[i], dp[i - 2] + arr[i]);              // 이전 잔을 안 마시고 현재 잔을 마시는 경우
        dp[i] = max(dp[i], dp[i - 3] + arr[i - 1] + arr[i]); // 이전 잔과 그 전 잔을 마시고 현재 잔을 마시는 경우
        dp[i] = max(dp[i], dp[i - 1]);                       // 이전 잔까지의 최대값과 비교(마시지 않는 경우)
    }
    cout << dp[n] << '\n';
}