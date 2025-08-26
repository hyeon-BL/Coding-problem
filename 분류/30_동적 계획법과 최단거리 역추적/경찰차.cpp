#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, W;
vector<pair<int, int>> cases;
vector<vector<int>> dp;   // dp[i][j]: car1는 i번째 사건, car2는 j번째 사건에 대응하는 최소 거리
vector<vector<int>> path; // path[i][j]: car1는 i번째 사건, car2는 j번째 사건에 대응하는 경로

int distance(pair<int, int> a, pair<int, int> b)
{ // Calculate Manhattan distance
    return abs(a.first - b.first) + abs(a.second - b.second);
}

int solve(int car1, int car2)
{ // Recursive function for DP
    int next_case = max(car1, car2) + 1;
    if (next_case > W)
        return 0;

    if (dp[car1][car2] != -1)
        return dp[car1][car2];

    int dist1 = distance(car1 == 0 ? make_pair(1, 1) : cases[car1 - 1], cases[next_case - 1]);
    int dist2 = distance(car2 == 0 ? make_pair(N, N) : cases[car2 - 1], cases[next_case - 1]);

    int option1 = solve(next_case, car2) + dist1;
    int option2 = solve(car1, next_case) + dist2;

    if (option1 < option2)
    { // Car 1이 더 가까운 경우
        dp[car1][car2] = option1;
        path[car1][car2] = 1;
    }
    else
    { // Car 2가 더 가까운 경우
        dp[car1][car2] = option2;
        path[car1][car2] = 2;
    }

    return dp[car1][car2];
}

void reconstruct(int car1, int car2)
{ // Path reconstruction
    int next_case = max(car1, car2) + 1;
    if (next_case > W)
        return;

    if (path[car1][car2] == 1)
    {
        cout << "1\n";
        reconstruct(next_case, car2);
    }
    else
    {
        cout << "2\n";
        reconstruct(car1, next_case);
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> W;

    cases.resize(W);
    for (int i = 0; i < W; i++)
    {
        cin >> cases[i].first >> cases[i].second;
    }

    dp.assign(W + 1, vector<int>(W + 1, -1));
    path.assign(W + 1, vector<int>(W + 1, -1));

    cout << solve(0, 0) << "\n";
    reconstruct(0, 0);

    return 0;
}