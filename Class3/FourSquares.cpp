#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    int* dp = new int[n + 1];
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
        dp[i] = i; // maximum squares required is i (1*1 + 1*1 + ...)
        for (int j = 1; j * j <= i; ++j) {
            dp[i] = min(dp[i], dp[i - j * j] + 1); // 이전 값을 바탕으로 현재 값을 구함(뺏을 때의 값 + 1)
        }
    }

    cout << dp[n] << '\n';
    return 0;
}