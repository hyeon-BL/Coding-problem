#include <iostream>
using namespace std;

long long modular_pow(long long base, long long exponent, int modulus)
{
    long long result = 1;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
        {
            result = (result * base) % modulus; // 중간에 나머지 연산 및 저장 -> 오버플로우 방지
        }
        base = (base * base) % modulus;
        exponent = exponent / 2; // 지수를 절반으로 줄임
    }
    return result;
}
// example)
// A^16 = (A^8)^2 = ((A^4)^2)^2 = (((A^2)^2)^2)^2
// divide and conquer -> O(logN)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int A, B, C;
    cin >> A >> B >> C;

    cout << modular_pow(A, B, C);
}