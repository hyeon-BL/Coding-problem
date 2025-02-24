#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

/*
ccw: counter clockwise
1. 세 점 p, q, r이 주어졌을 때, p->q->r이 반시계 방향인지 시계 방향인지 확인
2. p->q->r이 한 직선 위에 있는지 확인
3. 두 선분이 교차하는지 확인
예외) 두 선분이 한 직선 위에 있는 경우 -> 두 선분이 겹치는지 확인


union-find: Disjoint Set
1. 서로소 집합을 표현하기 위한 자료구조
2. 두 집합을 합치거나 두 원소가 같은 집합에 속해있는지 확인하는 연산을 지원
3. 각 집합의 대표 원소를 저장하는 배열 parent[]와 각 집합의 크기를 저장하는 배열 size[]를 사용

*/

struct Point
{
    int x, y;
};

struct Line
{
    Point p1, p2;
};

int orientation(Point p, Point q, Point r)
{ // 0: 한직선 / 1: 시계방향 / 2: 반시계방향
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
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

class UnionFind
{ // Disjoint Set -> 맞닿아있는 직선들을 하나의 그룹으로 묶기 위해 사용
public:
    UnionFind(int n) : parent(n), rank(n, 0), size(n, 1)
    {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void unite(int u, int v)
    {
        int root_u = find(u);
        int root_v = find(v);
        if (root_u != root_v)
        {
            if (rank[root_u] > rank[root_v])
            {
                parent[root_v] = root_u;
                size[root_u] += size[root_v];
            }
            else
            {
                parent[root_u] = root_v;
                size[root_v] += size[root_u];
                if (rank[root_u] == rank[root_v])
                    rank[root_v]++;
            }
        }
    }

    int getSize(int u)
    {
        return size[find(u)];
    }

private:
    vector<int> parent, rank, size;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<Line> lines(N);
    for (int i = 0; i < N; i++)
    {
        cin >> lines[i].p1.x >> lines[i].p1.y >> lines[i].p2.x >> lines[i].p2.y;
    }

    UnionFind uf(N);
    for (int i = 0; i < N; i++)
    { // 서로 교차하는 직선들을 하나의 그룹으로 묶기
        for (int j = i + 1; j < N; j++)
        { // i번째 직선과 j번째 직선이 교차하는지 확인
            if (doIntersect(lines[i].p1, lines[i].p2, lines[j].p1, lines[j].p2))
            {
                uf.unite(i, j);
            }
        }
    }

    int max_group_size = 0;
    set<int> unique_groups;
    for (int i = 0; i < N; i++)
    { // 가장 큰 그룹의 크기 찾기 및 그룹의 개수 찾기
        int root = uf.find(i);
        unique_groups.insert(root);
        max_group_size = max(max_group_size, uf.getSize(i));
    }

    cout << unique_groups.size() << '\n';
    cout << max_group_size;
    return 0;
}