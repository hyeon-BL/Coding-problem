#include <iostream>
#include <cmath>
using namespace std;

#define M_PI 3.14159265358979323846

struct Circle
{
    double x, y, r;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    Circle c1, c2;
    cin >> c1.x >> c1.y >> c1.r;
    cin >> c2.x >> c2.y >> c2.r;

    double dist = sqrt((c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y));

    cout << fixed;
    cout.precision(3);
    // 두 원이 겹치지 않는 경우
    if (dist >= c1.r + c2.r)
    {
        cout << "0.000";
        return 0;
    }

    // 한 원이 다른 원을 완전히 포함하는 경우
    if (dist <= abs(c1.r - c2.r))
    {
        double r_min = min(c1.r, c2.r);
        cout << M_PI * r_min * r_min;
        return 0;
    }

    // 두 원이 일부만 겹치는 경우
    double r1_sq = c1.r * c1.r;
    double r2_sq = c2.r * c2.r;

    // 코사인 법칙을 이용하여 각도를 구함
    double alpha = 2 * acos((r1_sq + dist * dist - r2_sq) / (2 * c1.r * dist));
    double beta = 2 * acos((r2_sq + dist * dist - r1_sq) / (2 * c2.r * dist));

    // 부채꼴에서 삼각형을 뺀 넓이를 구함
    double area1 = 0.5 * r1_sq * (alpha - sin(alpha));
    double area2 = 0.5 * r2_sq * (beta - sin(beta));

    double overlapArea = area1 + area2;

    cout << overlapArea;
}
