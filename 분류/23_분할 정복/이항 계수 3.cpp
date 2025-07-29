#include <iostream>
#include <vector>
using namespace std;

#define divider 1'000'000'007

vector<long long> fact, inv_fact; // 팩토리얼과 역원의 벡터

// 거듭제곱 계산 (분할 정복)
long long power(long long base, long long exp, long long mod)
{
    long long result = 1;
    while (exp > 0)
    {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

// 팩토리얼과 역원 계산
void precompute_factorials(int n)
{
    fact.resize(n + 1);
    inv_fact.resize(n + 1);
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        fact[i] = (fact[i - 1] * i) % divider;
    }
    inv_fact[n] = power(fact[n], divider - 2, divider); // n!의 역원
    for (int i = n - 1; i >= 0; i--)
    {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % divider;
    }
}

// 이항 계수 계산
long long binomial_coefficient(int n, int k)
{
    if (k < 0 || k > n)
        return 0;
    return (fact[n] * inv_fact[k] % divider) * inv_fact[n - k] % divider;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    precompute_factorials(N); // 팩토리얼과 역원 미리 계산
    cout << binomial_coefficient(N, K) << '\n';

    return 0;
}

/*
참고 : https://velog.io/@junttang/BOJ-11401-%EC%9D%B4%ED%95%AD-%EA%B3%84%EC%88%98-3-%ED%95%B4%EA%B2%B0-%EC%A0%84%EB%9E%B5-C

*/