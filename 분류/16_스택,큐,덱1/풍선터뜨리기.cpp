#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 풍선 개수
    cin >> N;
    vector<pair<int, int>> balloons; // 벡터 선언
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        balloons.push_back({x, i + 1}); // 벡터에 풍선 값과 인덱스 추가
    }

    int idx = 0; // 현재 인덱스
    while (!balloons.empty())
    {
        cout << balloons[idx].second << ' '; // 제거할 풍선의 인덱스

        int val = balloons[idx].first;          // 현재 인덱스의 풍선 값
        balloons.erase(balloons.begin() + idx); // 풍선 제거

        if (balloons.empty())
            break;

        if (val > 0)
        { // 양수인 경우
            idx = (idx + val - 1) % balloons.size();
        }
        else
        { // 음수인 경우
            int move = idx + val;
            while (move < 0)
            { // 음수 이동 처리
                move += balloons.size();
            }
            idx = move % balloons.size(); // 새로운 인덱스 계산
        }
    }
}