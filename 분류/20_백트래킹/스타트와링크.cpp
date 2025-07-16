#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<vector<int>> abilities;
int n;

int findMinDifference(int idx, int team1, int team2, int count1, int count2)
{
    if (count1 > n / 2 || count2 > n / 2) // 인원 초과
        return INT_MAX;

    if (idx == n) // 모든 플레이어 배정
    {
        if (count1 == n / 2 && count2 == n / 2)
        { // 팀이 정확히 n/2명씩 배정되었을 때
            int team1Score = 0, team2Score = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if ((team1 & (1 << i)) && (team1 & (1 << j))) // team1에 속한 경우
                        team1Score += abilities[i][j];
                    if ((team2 & (1 << i)) && (team2 & (1 << j))) // team2에 속한 경우
                        team2Score += abilities[i][j];
                }
            }
            return abs(team1Score - team2Score);
        }
        return INT_MAX; // 이외 케이스
    }

    // 현재 플레이어를 team1에 추가
    int diff1 = findMinDifference(idx + 1, team1 | (1 << idx), team2, count1 + 1, count2);

    // 현재 플레이어를 team2에 추가
    int diff2 = findMinDifference(idx + 1, team1, team2 | (1 << idx), count1, count2 + 1);

    return min(diff1, diff2); // 두 경우 중 최소값 반환
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n;
    abilities.resize(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> abilities[i][j];
        }
    }

    int minDifference = findMinDifference(0, 0, 0, 0, 0);
    cout << minDifference << "\n";
    return 0;
}