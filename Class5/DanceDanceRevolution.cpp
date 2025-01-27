#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int getWeight(int from, int to)
{ // from에서 to로 이동하는데 걸리는 시간 반환
    if (from == 0)
        return 2;
    if (from == to)
        return 1;
    if ((from == 1 && to == 3) || (from == 3 && to == 1) || (from == 2 && to == 4) || (from == 4 && to == 2))
        return 4;
    return 3;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> instructions;
    while (1)
    {
        int instruction;
        cin >> instruction;
        if (instruction == 0)
        {
            break;
        }
        instructions.push_back(instruction);
    }

    vector<vector<vector<int>>> dp(instructions.size() + 1, vector<vector<int>>(5, vector<int>(5, INT_MAX)));
    dp[0][0][0] = 0;

    for (int i = 0; i < instructions.size(); i++)
    { // i번째 instruction까지 수행했을 때, 왼발이 left, 오른발이 right에 있을 때 걸린 시간
        for (int left = 0; left < 5; left++)
        { // 왼발이 left에 있을 때
            for (int right = 0; right < 5; right++)
            { // 오른발이 right에 있을 때
                if (dp[i][left][right] == INT_MAX)
                    continue;
                int next = instructions[i];
                if (right != next) // 두 발이 같은 위치 X
                {                  // 왼발을 next로 옮기는 경우
                    dp[i + 1][next][right] = min(dp[i + 1][next][right], dp[i][left][right] + getWeight(left, next));
                }
                if (left != next) // 두 발이 같은 위치 X
                {                 // 오른발을 next로 옮기는 경우
                    dp[i + 1][left][next] = min(dp[i + 1][left][next], dp[i][left][right] + getWeight(right, next));
                }
            }
        }
    }

    int min_time = INT_MAX;
    for (int left = 0; left < 5; left++)
    { // 왼발이 left에 있을 때
        for (int right = 0; right < 5; right++)
        { // 오른발이 right에 있을 때
            min_time = min(min_time, dp[instructions.size()][left][right]);
        }
    }

    cout << min_time;
}