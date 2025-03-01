#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, K;
    cin >> N >> M >> K;
    vector<int> nums(M);
    for (int i = 0; i < M; i++)
    {
        cin >> nums[i];
    }
    vector<int> chulsu_nums(K);
    for (int i = 0; i < K; i++)
    {
        cin >> chulsu_nums[i];
    }

    sort(nums.begin(), nums.end()); // 오름차순 정렬
    set<int> available_nums(nums.begin(), nums.end());

    vector<int> minsu_nums;
    for (int chulsu_num : chulsu_nums)
    {
        auto it = available_nums.upper_bound(chulsu_num);
        if (it != available_nums.end())
        { // chulsu_num보다 큰 수가 존재하는 경우 -> 존재하는 수 중 가장 작은 수
            // 문제 조건 상 항상 존재
            minsu_nums.push_back(*it);
            available_nums.erase(it); // red-black tree -> O(logN)
        }
    }

    for (int minsu_num : minsu_nums)
    {
        cout << minsu_num << "\n";
    }
    return 0;
}

/*
10775 공항 참조

이 문제에서는 삭제 연산만 있어 tree set보다 union-find가 더 효율적이다.
tree set(=set)은 red-black tree: O(logN)
union-find: O(1) (amortized)
*/