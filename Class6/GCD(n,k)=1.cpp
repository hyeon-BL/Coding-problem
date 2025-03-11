#include <iostream>
#include <vector>
using namespace std;

// Euler's Totient Function
long long eulerTotient(long long n)
{ // 오일러 피 함수: n보다 작고 n과 서로소인 수의 개수
    long long result = n;
    for (long long p = 2; p * p <= n; ++p)
    {
        if (n % p == 0)
        { // 소인수 분해
            while (n % p == 0)
            {
                n /= p;
            }
            result -= result / p; // n(1-1/p) = n - n/p
        }
    }
    if (n > 1)
    {
        result -= result / n; // n(1-1/p) = n - n/p
    }
    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    cin >> n;
    cout << eulerTotient(n);
}