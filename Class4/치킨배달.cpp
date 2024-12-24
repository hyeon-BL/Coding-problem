#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
vector<pair<int, int>> houses;
vector<pair<int, int>> chicken_stores;
int min_distance = 999999;

int calculate_distance(const vector<int> &selected)
{
    int total_distance = 0;
    for (const auto &house : houses)
    {
        int hx = house.first;
        int hy = house.second;
        int min_dist = 999999;
        for (int idx : selected)
        { // 선택된 치킨집 중 가장 가까운 치킨집과의 거리 계산
            // 문제 조건에 주어진 맨해튼 거리
            int cx = chicken_stores[idx].first;
            int cy = chicken_stores[idx].second;
            min_dist = min(min_dist, abs(hx - cx) + abs(hy - cy));
        }
        total_distance += min_dist;
    }
    return total_distance;
}

void backtrack(vector<int> &selected, int start)
{ // 치킨집을 하나씩 추가하며 최소 치킨거리를 갖는 m개의 치킨집 선택
    if (selected.size() == m)
    {
        int current_distance = calculate_distance(selected); // 도시의 치킨거리 계산
        min_distance = min(min_distance, current_distance);  // 최소 치킨거리 갱신
        return;
    }
    for (int i = start; i < chicken_stores.size(); ++i)
    { // 치킨집 선택
        selected.push_back(i);
        backtrack(selected, i + 1); // 다음 치킨집 선택
        selected.pop_back();
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> n >> m;
    for (int i = 0; i < n; ++i)
    { // 집과 치킨집 위치 저장
        for (int j = 0; j < n; ++j)
        {
            int value;
            cin >> value;
            if (value == 1)
            { // house
                houses.push_back({i, j});
            }
            else if (value == 2)
            { // chicken store
                chicken_stores.push_back({i, j});
            }
        }
    }

    vector<int> selected;
    backtrack(selected, 0);

    cout << min_distance;

    return 0;
}