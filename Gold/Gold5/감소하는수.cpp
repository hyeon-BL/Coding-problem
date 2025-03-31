#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;              // N번째 감소하는 수
int cnt = 0;        // 감소하는 수의 개수
long long ans = -1; // 감소하는 수의 값 (초기값 -1)

void backtrack(int leng, long long num)
{
    if (leng == 0)
    { // 길이가 0이면 종료
        if (cnt == N)
        { // N번째 감소하는 수를 찾았을 때
            ans = num;
        }
        cnt++;
        return;
    }
    if (cnt > N)
        return;          // N번째 감소하는 수를 찾았으면 종료
    int last = num % 10; // 마지막 자리수
    if (num == 0)
        last = 10; // num이 0일 때는 마지막 자리수를 10으로 설정

    for (int i = 0; i <= last - 1; i++)
    { // 마지막 자리수보다 작은 수를 선택(0~last-1 -> 정렬된 상태)
        if (i == 0 && num == 0)
            continue;                      // num이 0일 때는 0을 선택하지 않음
        backtrack(leng - 1, num * 10 + i); // 다음 자리수로 이동
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    for (int i = 0; i <= 10; i++)
    { // 각 자리수로 시작
        backtrack(i, 0);
    }

    cout << ans;
    return 0;
}