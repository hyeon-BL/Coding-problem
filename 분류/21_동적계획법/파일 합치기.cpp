#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int K;
        cin >> K;

        vector<int> chapters(K + 1);
        vector<vector<int>> dp(K + 1, vector<int>(K + 1, 0)); // i~j 구간의 최소 비용
        vector<int> sum(K + 1, 0);                            // 누적합 배열
        for (int i = 1; i <= K; i++)
        {
            int x;
            cin >> x;
            chapters[i] = x;
            sum[i] = sum[i - 1] + chapters[i];
        }

        // DP
        for (int len = 2; len <= K; len++)
        { // 연속된 챕터의 길이
            for (int i = 1; i <= K - len + 1; i++)
            {                        // 시작 인덱스
                int j = i + len - 1; // 끝 인덱스
                dp[i][j] = INT_MAX;  // 초기화

                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
                }
            }
        }

        cout << dp[1][K] << "\n";
    }
}

/*
1. 파일을 2개씩 합치는 경우
- j = i + 1
- dp[i][j] = chapters[i] + chapters[j]

2. 파일을 3개 이상씩 합치는 경우
- dp[i][j] = dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]
- k는 i와 j 사이의 모든 인덱스
- 이 때 sum[j] - sum[i - 1]은 최종 합치는 단계에서 변하지 않음
*/