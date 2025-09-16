#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    vector<long long> cows(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> cows[i];

    vector<long long> S(N + 1, 0); // 누적 합 배열
    for (int i = 1; i <= N; i++)
        S[i] = S[i - 1] + cows[i];

    vector<long long> dp(N + 1, 0);          // dp[i]: i번째 소까지 고려했을 때 최대 효율성
    priority_queue<pair<long long, int>> pq; // (효율성, 인덱스)

    for (int i = 1; i <= N; i++)
    {
        pq.push({dp[i - 1] - S[i], i});
        while (!pq.empty() && pq.top().second < i - K)
            pq.pop();

        if (i > K)
            dp[i] = pq.top().first + S[i];
        else
            dp[i] = S[i];
    }

    cout << dp[N];
    return 0;
}

/*
dp[i] = dp[j] + (S[i] - S[j]) (i-K <= j < i)
       = (dp[j] - S[j]) + S[i] (i-K <= j < i)

*/