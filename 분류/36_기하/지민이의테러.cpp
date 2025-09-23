#include <iostream>
#include <vector>
using namespace std;

struct Point
{
    double x, y;
};

typedef vector<Point> Polygon;

bool is_on_segment(const Point &a, const Point &b, const Point &p)
{                                                                    // p가 a와 b를 잇는 선분 위에 있는지 확인
    return (min(a.x, b.x) <= p.x && p.x <= max(a.x, b.x)) &&         // x좌표가 a.x와 b.x 사이에 있는지
           (min(a.y, b.y) <= p.y && p.y <= max(a.y, b.y)) &&         // y좌표가 a.y와 b.y 사이에 있는지
           ((b.x - a.x) * (p.y - a.y) == (b.y - a.y) * (p.x - a.x)); // 벡터 ab와 ap가 평행한지

    /*
    해당 반례:
10
0 0
6 0
6 6
3 6
3 4
4 4
4 2
2 2
2 4
0 4
1 1 3 3 5 5 -> 1 0 1
    */
}

bool is_inside(const Polygon &poly, const Point &p)
{
    int n = poly.size();
    bool inside = false;

    for (int i = 0; i < n; i++)
    {
        int j = (i + 1) % n;

        if (is_on_segment(poly[i], poly[j], p))
        {
            // p는 poly[i]와 poly[j]를 잇는 경계에 위치
            return true;
        }

        if ((poly[i].y > p.y) != (poly[j].y > p.y))
        { // 오른쪽 반직선과 교점이 짝수개이면 밖에, 홀수개이면 안에
            double crossX = (poly[j].x - poly[i].x) * (p.y - poly[i].y) / (poly[j].y - poly[i].y) + poly[i].x;

            if (p.x < crossX)
                inside = !inside;
        }
    }

    return inside;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    Polygon poly(n);

    for (int i = 0; i < n; i++)
        cin >> poly[i].x >> poly[i].y;

    Point p1, p2, p3;
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    cout << is_inside(poly, p1) << '\n'
         << is_inside(poly, p2) << '\n'
         << is_inside(poly, p3) << '\n';
}