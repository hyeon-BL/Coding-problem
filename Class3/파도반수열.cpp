#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    int T;
    cin >> T;

    long long dp[101] = {0};
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;

    for (int i = 4; i <= 100; i++) {
        dp[i] = dp[i-2] + dp[i-3];
    }

    while (T--) {
        int N;
        cin >> N;
        cout << dp[N] << '\n';
    }
}