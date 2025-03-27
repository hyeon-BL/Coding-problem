#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T; // 테스트 케이스

    while (T--)
    {
        long long x, y;
        cin >> x >> y;          // x: 시작점, y: 도착점
        long long dist = y - x; // 거리

        // steps: 이동 횟수, move: 이동 거리, covered: 이동한 거리
        long long steps = 0, move = 1, covered = 0;
        while (covered + move < dist)
        {
            steps++;
            covered += move;
            if (steps % 2 == 0)
                move++; // 짝수번째 이동일 때 이동 거리 증가(홀수번에 감소시켜야 함)
        }
        steps++; // 마지막 이동 추가
        cout << steps << '\n';
    }
}