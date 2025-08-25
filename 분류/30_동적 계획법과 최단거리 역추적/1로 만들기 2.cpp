#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> dp(N + 1, 0);
    vector<int> track(N + 1, -1);

    // Bottom-Up 방식으로 DP 계산
    for (int i = 2; i <= N; i++)
    {
        dp[i] = dp[i - 1] + 1; // 1을 빼는 경우
        track[i] = i - 1;

        if (i % 2 == 0 && dp[i / 2] + 1 < dp[i])
        {
            dp[i] = dp[i / 2] + 1; // 2로 나누는 경우
            track[i] = i / 2;
        }

        if (i % 3 == 0 && dp[i / 3] + 1 < dp[i])
        {
            dp[i] = dp[i / 3] + 1; // 3으로 나누는 경우
            track[i] = i / 3;
        }
    }

    // 최소 연산 횟수 출력
    cout << dp[N] << "\n";

    // 경로 추적
    for (int i = N; i != -1; i = track[i])
    {
        cout << i << " ";
        if (i == 1)
            break;
    }
    return 0;
}

/*
Top-Down 방식으로 DP 계산
-> overflow

int make_one(int n) {
    if (n == 1)
        return 0;
    if (dp[n] != -1)
        return dp[n];

    // 1을 빼는 경우
    int res = make_one(n - 1) + 1;
    track[n] = n - 1; // n-1로 이동

    // 2로 나누는 경우
    if (n % 2 == 0) {
        int temp = make_one(n / 2) + 1;
        if (temp < res) {
            res = temp;
            track[n] = n / 2; // n/2로 이동
        }
    }

    // 3으로 나누는 경우
    if (n % 3 == 0) {
        int temp = make_one(n / 3) + 1;
        if (temp < res) {
            res = temp;
            track[n] = n / 3; // n/3로 이동
        }
    }

    return dp[n] = res;
}
*/