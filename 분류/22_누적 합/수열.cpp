#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;
    vector<int> arr(N + 1);
    for (int i = 1; i <= N; i++)
        cin >> arr[i];

    vector<int> cumulative_sum(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cumulative_sum[i] = cumulative_sum[i - 1] + arr[i];

    int max_sum = INT_MIN;
    for (int i = 1; i <= N - K + 1; i++)
    {
        int current_sum = cumulative_sum[i + K - 1] - cumulative_sum[i - 1];
        max_sum = max(max_sum, current_sum);
    }
    cout << max_sum;
}