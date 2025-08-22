#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_WEIGHT 40000
#define OFFSET MAX_WEIGHT // Offset for negative weights

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> weights(N);
    for (int i = 0; i < N; i++)
        cin >> weights[i];

    // DP 배열 초기화(dp[i][OFFSET + j] = i번째 추를 사용했을 때, 무게 차이가 j인 경우)
    vector<vector<bool>> dp(N + 1, vector<bool>(2 * MAX_WEIGHT + 1, false));
    dp[0][OFFSET] = true; // 초기 상태: 무게 차이가 0인 경우

    // DP 계산
    for (int i = 1; i <= N; i++)
    {
        for (int j = 0; j <= 2 * MAX_WEIGHT; j++)
        {
            if (dp[i - 1][j])
            {
                dp[i][j] = true; // 추를 사용하지 않는 경우
                if (j + weights[i - 1] <= 2 * MAX_WEIGHT)
                    dp[i][j + weights[i - 1]] = true; // 추를 한쪽 저울에 올리는 경우

                if (j - weights[i - 1] >= 0)
                    dp[i][j - weights[i - 1]] = true; // 추를 다른쪽 저울에 올리는 경우
            }
        }
    }

    // 목표값 확인
    int T;
    cin >> T;
    while (T--)
    {
        int target;
        cin >> target;

        if (dp[N][OFFSET + target])
            cout << "Y "; // 목표값이 가능한 경우

        else
            cout << "N "; // 목표값이 불가능한 경우
    }

    return 0;
}