#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    vector<pair<int, int>> arr(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }

    sort(arr.begin() + 1, arr.end());

    vector<int> dp(n + 1, 1);
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (arr[j].second < arr[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // 교차하지 않는 전기줄(LIS)의 최대 개수
    int lis = *max_element(dp.begin(), dp.end());
    cout << n - lis; // 제거해야 하는 전기줄의 최소 개수
    return 0;
}