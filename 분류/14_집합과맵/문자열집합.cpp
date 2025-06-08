#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    int cnt = 0;
    cin >> N >> M; // N: 집합 S에 속하는 원소의 개수, M: 검사해야 할 원소의 개수
    vector<string> S(N);
    for (int i = 0; i < N; ++i)
    {
        cin >> S[i];
    }
    unordered_map<string, int> mp; // 문자열을 키로 하는 해시맵
    for (int i = 0; i < M; i++)
    {
        string str;
        cin >> str; // 검사할 문자열 입력
        if (mp.find(str) == mp.end())
        {                // 해시맵에 없는 문자열이면
            mp[str] = 1; // 해시맵에 추가
        }
        else
        {              // 해시맵에 있는 문자열이면
            mp[str]++; // 카운트 증가
        }
    }
    for (const auto &str : S)
    { // 집합 S에 속하는 원소들에 대해
        if (mp.find(str) != mp.end())
        {                   // 해시맵에 있는지 확인
            cnt += mp[str]; // 카운트 증가
        }
    }
    cout << cnt << '\n'; // 집합 S에 속하는 원소의 개수 출력
}

/*
"find" time complexity
list: O(N)
unordered_map: O(1) on average, O(N) in the worst case -> hash table lookup
set: O(log N) -> binary search tree lookup


"insert" time complexity
list: O(1)
unordered_map: O(1) on average, O(N) in the worst case
set: O(log N)

"erase" time complexity
list: O(1)
unordered_map: O(1) on average, O(N) in the worst case
set: O(log N)
unordered_map is generally faster than set for lookups, insertions, and deletions due to its average O(1) time complexity.
*/