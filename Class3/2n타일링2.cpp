#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 1 << endl;
        return 0;
    }

    long long* dp = new long long[n + 1];
    dp[0] = 1; // 1 way to fill 2*0 rectangle (do nothing)
    dp[1] = 1; // 1 way to fill 2*1 rectangle (1 vertical tile)

    for (int i = 2; i <= n; ++i) {
        dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
    }

    cout << dp[n];
    delete[] dp;
}