#include <iostream>
using namespace std;

/*
ccw: counter clockwise
1. 세 점 p, q, r이 주어졌을 때, p->q->r이 반시계 방향인지 시계 방향인지 확인
2. p->q->r이 한 직선 위에 있는지 확인
3. 두 선분이 교차하는지 확인
예외) 두 선분이 한 직선 위에 있는 경우 -> 두 선분이 겹치는지 확인

추가 고려사항) long long으로 계산하는 이유 -> int로 계산하면 오버플로우 발생 가능
int 자료형을 더하여 long long으로 묵시적 변환하면 오버플로우 발생 가능
=> 처음부터 long long으로 계산
*/

struct Point
{
    long long x, y;
};

int orientation(Point p, Point q, Point r)
{ // 0: 한직선 / 1: 시계방향 / 2: 반시계방향
    long long val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0)
        return 0;
    return (val > 0) ? 1 : 2;
}

bool onSegment(Point p, Point q, Point r)
{ // q가 p와 r 사이에 있는지 확인 (p, q, r이 한 직선 위에 있을 때)
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
        return true;
    return false;
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);

    if (o1 != o2 && o3 != o4) // 서로 다른 방향에 있는 경우(ccw <= 0 조건)
        return true;

    if (o1 == 0 && onSegment(p1, p2, q1))
        return true;
    if (o2 == 0 && onSegment(p1, q2, q1))
        return true;
    if (o3 == 0 && onSegment(p2, p1, q2))
        return true;
    if (o4 == 0 && onSegment(p2, q1, q2))
        return true;

    return false;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    Point p1, q1, p2, q2;
    cin >> p1.x >> p1.y >> q1.x >> q1.y;
    cin >> p2.x >> p2.y >> q2.x >> q2.y;

    if (doIntersect(p1, q1, p2, q2))
        cout << 1;
    else
        cout << 0;
}