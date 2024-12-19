#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> sequence(N);
    for (int i = 0; i < N; i++)
    {
        cin >> sequence[i];
    }

    vector<int> dp(N, 1); // dp[i] will store the length of the longest increasing subsequence ending at index i

    int maxLength = 1;
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (sequence[i] > sequence[j])
            { // increasing subsequence
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        maxLength = max(maxLength, dp[i]); // update the maximum length
    }

    cout << maxLength;
    return 0;
}