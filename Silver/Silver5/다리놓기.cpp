#include<iostream>
using namespace std;

long combination(int n, int k) {
    if (k > n - k) k = n - k;
    int* dp = new int[k + 1]();
    dp[0] = 1;
    for (int i = 1; i <= n; i++) { // nCk = (n-1)Ck + (n-1)C(k-1)
        for (int j = min(i, k); j > 0; j--) {
            dp[j] = dp[j] + dp[j - 1];
        }
    }
    return dp[k];
}

int main() {
    int T;
    cin >> T;
    int N, M;
    while (T--) {
        cin >> N >> M;
        cout << combination(M, N) << endl;
    }
}