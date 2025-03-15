#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Graham Scan 알고리즘
- 볼록 껍질을 구하는 알고리즘 중 하나
- 시계 방향으로 정렬된 점들을 순회하면서 볼록 껍질을 구함
- 볼록 껍질: 점들을 모두 포함하는 가장 작은 볼록 다각형
- 볼록 다각형: 모든 내각이 180도 미만인 다각형

1. 가장 아래에 있는 점을 찾음
2. 이 점을 기준으로 시계 방향으로 정렬
3. 시계 방향으로 정렬된 점들을 순회하면서 볼록 껍질을 구함
*/

struct Point
{
    long long x, y;
    bool operator<(const Point &p) const
    { // x좌표 오름차순, x좌표가 같으면 y좌표 오름차순
        return x < p.x || (x == p.x && y < p.y);
    }
};

long long cross(const Point &O, const Point &A, const Point &B)
{ // OA, OB 벡터의 외적 (result > 0: 반시계 방향, result < 0: 시계 방향, result == 0: 일직선)
    return (A.x - O.x) * (B.y - O.y) - (A.y - O.y) * (B.x - O.x);
}

vector<Point> convexHull(vector<Point> &points)
{ // 볼록 껍질 알고리즘
    int n = points.size(), k = 0;
    if (n <= 3)
        return points;
    vector<Point> hull(2 * n);

    // 반시계 방향으로 정렬
    sort(points.begin(), points.end());

    // Build lower hull
    for (int i = 0; i < n; ++i)
    {
        while (k >= 2 && cross(hull[k - 2], hull[k - 1], points[i]) <= 0)
            k--; // 반시계 방향이 아니면 pop
        hull[k++] = points[i];
    }

    // Build upper hull
    for (int i = n - 1, t = k + 1; i >= 0; --i)
    {
        while (k >= t && cross(hull[k - 2], hull[k - 1], points[i]) <= 0)
            k--; // 반시계 방향이 아니면 pop
        hull[k++] = points[i];
    }

    hull.resize(k - 1);
    return hull;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 점의 개수
    cin >> N;
    vector<Point> points(N);
    for (int i = 0; i < N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    vector<Point> hull = convexHull(points);

    cout << hull.size();
}