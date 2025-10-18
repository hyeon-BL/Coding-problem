#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    cin >> n;

    // 1. 피사노 주기 적용
    // M = 1,000,000 일 때, 주기는 1,500,000 이다.
    long long M = 1000000;
    long long P = 1500000;
    n = n % P; // 피사노 주기 적용

    // 2. O(1) 메모리로 피보나치 계산
    if (n == 0)
    {
        cout << 0; // F(0)
        return 0;
    }
    if (n == 1)
    {
        cout << 1; // F(1)
        return 0;
    }

    // F(i-2), F(i-1) 값만 저장할 변수
    long long a = 0;       // F(0)
    long long b = 1;       // F(1)
    long long current = 1; // F(n)을 저장할 변수 (초기값 F(1))

    // F(2) 부터 F(n) 까지 계산
    for (long long i = 2; i <= n; i++)
    {
        // F(i) = F(i-1) + F(i-2)
        current = (a + b) % M;
        a = b;       // F(i-2)가 F(i-1)이 됨
        b = current; // F(i-1)이 F(i)가 됨
    }

    // 3. 최종 결과 출력
    cout << current;

    return 0;
}