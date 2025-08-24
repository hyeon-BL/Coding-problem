#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        vector<int> cards(N);
        for (int i = 0; i < N; i++)
        {
            cin >> cards[i];
        }

        // Total sum: i ~ j까지 점수 합
        vector<vector<int>> total_sum(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            total_sum[i][i] = cards[i];
            for (int j = i + 1; j < N; j++)
            {
                total_sum[i][j] = total_sum[i][j - 1] + cards[j];
            }
        }

        vector<vector<int>> dp(N, vector<int>(N, 0));

        // Base case: single card
        for (int i = 0; i < N; i++)
        {
            dp[i][i] = cards[i];
        }

        // DP table
        for (int length = 2; length <= N; length++)
        { // 부분 배열의 길이 순회
            for (int i = 0; i <= N - length; i++)
            {
                int j = i + length - 1; // End of the subarray
                dp[i][j] = max(cards[i] + (total_sum[i + 1][j] - dp[i + 1][j]),
                               cards[j] + (total_sum[i][j - 1] - dp[i][j - 1]));
            }
        }

        // 첫번째 플레이어의 최적 점수
        cout << dp[0][N - 1] << "\n";
    }

    return 0;
}

/*
Greedy approach - cannot guarantee optimal solution

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int N;
        cin >> N;

        deque<int> dq;
        for (int i = 0; i < N; i++)
        {
            int x;
            cin >> x;
            dq.push_back(x);
        }

        int score = 0;
        int turn = 0;
        while (!dq.empty())
        {
            int front = dq.front();
            int back = dq.back();
            if (front > back)
            {
                dq.pop_front();
                if (turn % 2 == 0)
                    score += front;
            }
            else
            {
                dq.pop_back();
                if (turn % 2 == 0)
                    score += back;
            }
            turn++;
        }
        cout << score << "\n";
    }
}
*/