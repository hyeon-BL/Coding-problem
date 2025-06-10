#include <iostream>
#include <set>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a, b; // a: 집합 A의 원소의 개수, b: 집합 B의 원소의 개수
    cin >> a >> b;

    set<int> A, B; // 집합 A와 B를 저장할 set
    for (int i = 0; i < a; ++i)
    {
        int x; // 집합 A의 원소
        cin >> x;
        A.insert(x); // 집합 A에 원소 추가 -> O(log n)
    }
    for (int i = 0; i < b; ++i)
    {
        int x; // 집합 B의 원소
        cin >> x;
        B.insert(x); // 집합 B에 원소 추가 -> O(log n)
    }

    set<int> intersection; // 교집합을 저장할 set
    for (const int &x : A)
    {
        if (B.find(x) != B.end())
        {                           // A의 원소가 B에도 존재하는지 확인
            intersection.insert(x); // 교집합에 추가
        }
    }
    int result = A.size() + B.size() - 2 * intersection.size(); // 대칭 차집합의 크기 계산
    cout << result << '\n';                                     // 결과 출력
}