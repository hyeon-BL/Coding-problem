#include <iostream>
#include <cmath>
using namespace std;

double doubleDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double shortestPath(double X, double Y, double D, double T)
{
    // (0, 0)에서 (X, Y)까지 직선 거리
    double directDistance = doubleDistance(0, 0, X, Y);

    // 직선 경로로 이동하는 경우
    double minTime = directDistance;

    // 점프를 사용하여 이동하는 경우
    if (D < directDistance)
    {
        // 점프 횟수 계산
        int jumps = static_cast<int>(directDistance / D);
        double remainingDistance = directDistance - jumps * D;

        // 점프 후 남은 거리를 걷는 경우
        double timeWithWalk = jumps * T + remainingDistance;
        minTime = min(minTime, timeWithWalk);

        // 점프 후 남은 거리를 한 번 더 점프하는 경우
        if (remainingDistance > 0)
        {
            double timeWithExtraJump = (jumps + 1) * T;
            minTime = min(minTime, timeWithExtraJump);
        }
    }
    else if (D > directDistance)
    {
        // 한 번 점프 시 넘어가는 경우
        double remainingDistance = D - directDistance;
        double timeWithExtraJump = T + min(remainingDistance, T);
        minTime = min(minTime, timeWithExtraJump);
    }
    else
    {
        // D == directDistance인 경우, 점프 한 번으로 도착 가능
        minTime = min(minTime, T);
    }

    return minTime;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    double X, Y, D, T;
    cin >> X >> Y >> D >> T;

    double result = shortestPath(X, Y, D, T);
    cout << fixed;
    cout.precision(9);
    cout << result;
}