#include <iostream>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
        return a;         // b가 0이면 a가 최대공약수
    return gcd(b, a % b); // 유클리드 호제법
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T; // 테스트 케이스 수 입력

    while (T--)
    {
        long long A, B;
        cin >> A >> B; // 두 정수 A와 B 입력

        long long G = gcd(A, B);
        long long L = (A * B) / G;

        cout << L << '\n'; // 최소공배수 출력
    }
}