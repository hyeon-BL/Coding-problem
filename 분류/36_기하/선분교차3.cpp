#include <iostream>
#include <cmath>
using namespace std;

struct Point
{
    double x, y;
};

struct line
{
    Point start, end;

    // CCW 함수
    int ccw(const Point &a, const Point &b, const Point &c) const
    {
        double op = a.x * b.y + b.x * c.y + c.x * a.y;
        op -= (a.y * b.x + b.y * c.x + c.y * a.x);
        if (op > 0)
            return 1; // counter clockwise
        if (op < 0)
            return -1; // clockwise
        return 0;      // collinear
    }

    // 선분이 겹치는지 확인하는 함수
    bool isOverlapping(const line &other) const
    {
        // L1에 대해 CCW 계산
        int d1 = ccw(start, end, other.start);
        int d2 = ccw(start, end, other.end);

        // L2에 대해 CCW 계산
        int d3 = ccw(other.start, other.end, start);
        int d4 = ccw(other.start, other.end, end);
        if (d1 * d2 < 0 && d3 * d4 < 0)
            return true; // 일반적인 경우, 두 선분이 교차함

        // 세 점이 일직선 상에 있는 경우 처리
        if (d1 == 0 && onSegment(start, end, other.start))
            return true;
        if (d2 == 0 && onSegment(start, end, other.end))
            return true;
        if (d3 == 0 && onSegment(other.start, other.end, start))
            return true;
        if (d4 == 0 && onSegment(other.start, other.end, end))
            return true;

        return false; // 교차하지 않음
    }

    // 점 p가 선분 ab 위에 있는지 확인하는 함수
    bool onSegment(const Point &a, const Point &b, const Point &p) const
    {
        return min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x) &&
               min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y);
    }

    // 교점의 좌표를 계산하는 함수
    Point intersectionPoint(const line &other) const
    {
        double A1 = end.y - start.y;
        double B1 = start.x - end.x;
        double C1 = A1 * start.x + B1 * start.y;

        double A2 = other.end.y - other.start.y;
        double B2 = other.start.x - other.end.x;
        double C2 = A2 * other.start.x + B2 * other.start.y;

        double determinant = A1 * B2 - A2 * B1;

        if (determinant == 0)
        {
            // 평행하거나 일치하는 경우
            if (min(start.x, end.x) == max(other.start.x, other.end.x) && min(start.y, end.y) == max(other.start.y, other.end.y))
                return {min(start.x, end.x), min(start.y, end.y)}; // 한 점에서 만나는 경우
            else if (min(other.start.x, other.end.x) == max(start.x, end.x) && min(other.start.y, other.end.y) == max(start.y, end.y))
                return {min(other.start.x, other.end.x), min(other.start.y, other.end.y)}; // 한 점에서 만나는 경우
            else if (min(start.x, end.x) == max(other.start.x, other.end.x) && max(start.y, end.y) == min(other.start.y, other.end.y))
                return {min(start.x, end.x), max(start.y, end.y)}; // 한 점에서 만나는 경우
            else if (min(other.start.x, other.end.x) == max(start.x, end.x) && max(other.start.y, other.end.y) == min(start.y, end.y))
                return {min(other.start.x, other.end.x), max(other.start.y, other.end.y)}; // 한 점에서 만나는 경우
            else
                return {NAN, NAN}; // 출력하지 않음
        }
        else
        {
            double x = (B2 * C1 - B1 * C2) / determinant;
            double y = (A1 * C2 - A2 * C1) / determinant;
            return {x, y};
        }
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    line l1, l2;
    cin >> l1.start.x >> l1.start.y >> l1.end.x >> l1.end.y;
    cin >> l2.start.x >> l2.start.y >> l2.end.x >> l2.end.y;
    cout.precision(10);
    cout << fixed;
    if (l1.isOverlapping(l2))
    {
        Point ip = l1.intersectionPoint(l2);
        if (!isnan(ip.x) && !isnan(ip.y))
            cout << "1\n"
                 << ip.x << ' ' << ip.y; // 교점이 존재하는 경우
        else
            cout << "1\n"; // 교점이 무한히 많은 경우 (일치하는 경우)
    }
    else
        cout << "0"; // 교차하지 않는 경우
}