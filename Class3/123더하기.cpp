#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        
        int dp[11] = {0}; // Assuming N will not be greater than 10
        dp[0] = 1; // Base case: There's one way to represent 0 (using no numbers)
        
        for (int i = 1; i <= N; ++i) {
            if (i >= 1) dp[i] += dp[i-1]; 
            if (i >= 2) dp[i] += dp[i-2];
            if (i >= 3) dp[i] += dp[i-3];
        }
        
        cout << dp[N] << '\n';
    }
}