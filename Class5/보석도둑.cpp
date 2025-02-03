#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

/*
0/1 Knapsack Problem 변형 -> 아이템을 1개만 넣을 수 있고, 가방이 여러개일 때(greedy algorithm)
- 물건의 개수 N, 가방의 개수 K
- 물건의 무게와 가격, 가방의 크기 입력
- 가방에 들어갈 수 있는 물건의 최대 가격을 출력
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K; // N: 물건의 개수, K: 가방 수
    cin >> N >> K;
    vector<pair<int, int>> item(N); // 물건의 무게와 가격
    vector<int> bag(K);             // 가방의 크기

    for (int i = 0; i < N; i++)
    { // 물건의 무게와 가격 입력
        cin >> item[i].first >> item[i].second;
    }
    for (int i = 0; i < K; i++)
    { // 가방의 크기 입력
        cin >> bag[i];
    }

    sort(item.begin(), item.end()); // 물건을 무게 기준 오름차순 정렬
    sort(bag.begin(), bag.end());   // 가방을 크기 기준 오름차순 정렬

    priority_queue<int> pq; // 최대 힙(누적되어 저장 -> 중복방지)
    long long answer = 0;
    int itemIndex = 0;

    for (int i = 0; i < K; i++)
    { // 작은 가방부터
        while (itemIndex < N && item[itemIndex].first <= bag[i])
        {
            pq.push(item[itemIndex].second); // 가방에 들어갈 수 있는 모든 보석을 힙에 추가
            itemIndex++;
        }
        if (!pq.empty())
        {
            answer += pq.top(); // 가장 가치가 높은 보석을 선택
            pq.pop();
        }
    }

    cout << answer;
}