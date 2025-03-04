#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
sweepline: 철도
- 집과 사무실의 거리 정보를 입력받음
- 집과 사무실 사이의 거리가 철로 길이보다 작거나 같은 경우를 찾음
- 특정 사무실을 기준으로 철로 길이를 만족하는 집들만 남기기
- 최대로 남은 집의 개수 출력

*/

struct Dist
{
    int home, office;
};

bool compare(const Dist &a, const Dist &b)
{ // office 오름차순 정렬
    return a.office < b.office;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;              // 집과 사무실의 개수
    vector<Dist> dists(n); // 집과 사무실의 거리 정보
    for (int i = 0; i < n; i++)
    {
        cin >> dists[i].home >> dists[i].office;
        if (dists[i].home > dists[i].office)
        { // 집이 사무실보다 멀리 있는 경우
            swap(dists[i].home, dists[i].office);
        }
    }
    int d;
    cin >> d; // 철로 길이

    sort(dists.begin(), dists.end(), compare); // office 오름차순 정렬

    priority_queue<int, vector<int>, greater<int>> pq; // 집 기준 min heap
    int max_count = 0;

    for (const auto &dist : dists)
    { // 모든 집과 사무실에 대해
        if (dist.office - dist.home <= d)
        { // 집과 사무실 사이의 거리가 철로 길이보다 작거나 같은 경우
            pq.push(dist.home);
        }
        while (!pq.empty() && pq.top() < dist.office - d)
        { // dist에 대해 철로 길이를 만족하는 집들만 남기기
            pq.pop();
        }
        max_count = max(max_count, static_cast<int>(pq.size()));
    }

    cout << max_count;
    return 0;
}