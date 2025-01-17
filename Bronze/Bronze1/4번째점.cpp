#include <iostream>
#include <iomanip>
using namespace std;

struct Point
{
    double x, y;

    Point(double x, double y) : x(x), y(y) {}
    Point() : Point(0, 0) {}

    Point operator+(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }

    Point operator-(const Point &p) const
    {
        return Point(x - p.x, y - p.y);
    }

    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    double x1, y1, x2, y2, x3, y3, x4, y4;
    while (cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4)
    {
        Point A(x1, y1), B(x2, y2), C(x3, y3), D(x4, y4);
        Point ano;
        if (A == C)
        {
            ano = B + D - A;
        }
        else if (A == D)
        {
            ano = B + C - A;
        }
        else if (B == C)
        {
            ano = A + D - B;
        }
        else
        {
            ano = A + C - B;
        }
        cout << fixed << setprecision(3) << ano.x << ' ' << ano.y << '\n';
    }
}

/*
기하 -> 공통 점 기준 두 벡터의 합 == 대각선 벡터 (평행사변형 원리)
  _______
 /      /
/______/


*/