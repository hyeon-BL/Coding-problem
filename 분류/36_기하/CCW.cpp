#include <iostream>
using namespace std;

struct Point
{
    int x, y;
};

int ccw(Point a, Point b, Point c)
{
    int op = a.x * b.y + b.x * c.y + c.x * a.y;
    op -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if (op > 0)
        return 1; // counter clockwise
    if (op < 0)
        return -1; // clockwise
    return 0;      // collinear
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;

    int result = ccw(p1, p2, p3);
    cout << result << '\n';
    return 0;
}