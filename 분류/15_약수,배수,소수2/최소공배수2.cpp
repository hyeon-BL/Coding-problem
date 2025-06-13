#include <iostream>
using namespace std;

long long lcm(long long a, long long b)
{
    long long gcd;
    long long temp_a = a;
    long long temp_b = b;
    while (temp_b != 0)
    {
        gcd = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = gcd;
    }
    return (a / gcd) * b; // 최소공배수 계산
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long A, B;
    cin >> A >> B;
    cout << lcm(A, B) << '\n'; // 최소공배수 출력
    return 0;
}