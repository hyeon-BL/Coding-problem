#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    int* score = new int[N+1];
    int* dp = new int[N+1];

    for (int i = 1; i <= N; i++) {
        cin >> score[i];
    }

    dp[0] = 0;
    dp[1] = score[1];
    if (N > 1) {
        dp[2] = score[1] + score[2];
    }

    for (int i = 3; i <= N; i++) {
        dp[i] = max(dp[i-2] + score[i], dp[i-3] + score[i-1] + score[i]);
    }

    cout << dp[N];

    delete[] score;
    delete[] dp;
}