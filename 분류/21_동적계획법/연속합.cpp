#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> dp(n, -1e9);
    dp[0] = arr[0];
    for (int i = 1; i < n; i++)
        dp[i] = max(dp[i - 1] + arr[i], arr[i]);

    int ans = -1e9;
    for (int i = 0; i < n; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";
}