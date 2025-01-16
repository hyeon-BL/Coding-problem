#include <iostream>
using namespace std;

bool large_prime_factors(long long S)
{
    for (long long i = 2; i <= 1'000'000; ++i)
    { // 1'000'000까지의 수로 나누어 떨어지면 false
        if (S % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    while (N--)
    {
        long long S;
        cin >> S;
        if (large_prime_factors(S))
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}