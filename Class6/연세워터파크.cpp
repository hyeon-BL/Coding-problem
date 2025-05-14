#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, D; // N: 징검다리의 개수, D: 임계치
    cin >> N >> D;
    vector<long long> stones(N + 1); // 징검다리에 적힌 수

    for (int i = 1; i <= N; i++)
    {
        cin >> stones[i];
    }

    // dp[i]: i번째 징검다리까지 고려했을 때의 최대 합
    vector<long long> dp(N + 1, LLONG_MIN);
    dp[1] = stones[1]; // 첫 번째 징검다리의 값으로 초기화

    // 우선순위 큐 (값, 인덱스) -> 최대 값을 빠르게 찾기 위해 사용
    priority_queue<pair<long long, int>> pq;
    pq.push({dp[1], 1});

    for (int i = 2; i <= N; i++)
    {
        // 임계치 D를 만족하지 않는 징검다리 제거
        while (!pq.empty() && abs(pq.top().second - i) > D)
        {
            pq.pop();
        }

        // 현재 징검다리의 최대 합 계산
        if (!pq.empty())
        {
            dp[i] = max(pq.top().first + stones[i], stones[i]);
        }
        else
        {
            dp[i] = stones[i];
        }

        // 현재 값을 우선순위 큐에 추가
        pq.push({dp[i], i});
    }

    // dp 배열에서 최대 값 출력
    cout << *max_element(dp.begin(), dp.end());

    return 0;
}