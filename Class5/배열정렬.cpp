#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <climits>
using namespace std;

struct State
{
    vector<int> arr;
    int cost;
    bool operator>(const State &other) const
    { // 우선순위 큐에서 최소값을 구하기 위해 오버로딩
        return cost > other.cost;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N; // 배열의 크기
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
        cin >> arr[i]; // 배열 입력받기

    int M;
    cin >> M;                                // 조작의 개수
    vector<pair<pair<int, int>, int>> op(M); // 조작의 정보(l, r, c)
    for (int i = 0; i < M; i++)
    {
        cin >> op[i].first.first >> op[i].first.second >> op[i].second;
        op[i].first.first--;  // 1-indexed -> 0-indexed
        op[i].first.second--; // 1-indexed -> 0-indexed
    }

    priority_queue<State, vector<State>, greater<State>> pq;
    pq.push({arr, 0});
    set<vector<int>> visited;

    while (!pq.empty())
    {
        State current = pq.top();
        pq.pop();

        if (is_sorted(current.arr.begin(), current.arr.end()))
        { // 정렬되었으면 출력
            cout << current.cost;
            return 0;
        }

        if (visited.count(current.arr))
            continue;
        visited.insert(current.arr);

        for (const auto &o : op)
        {
            int l = o.first.first;
            int r = o.first.second;
            int c = o.second;
            vector<int> new_arr = current.arr;    // 배열 복사
            swap(new_arr[l], new_arr[r]);         // 조작 수행
            pq.push({new_arr, current.cost + c}); // 다음 상태 추가
        }
    }

    cout << -1;
    return 0;
}