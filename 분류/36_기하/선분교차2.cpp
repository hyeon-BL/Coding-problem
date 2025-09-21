#include <iostream>
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
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    line l1, l2;
    cin >> l1.start.x >> l1.start.y >> l1.end.x >> l1.end.y;
    cin >> l2.start.x >> l2.start.y >> l2.end.x >> l2.end.y;
    cout << (l1.isOverlapping(l2) ? 1 : 0);
}