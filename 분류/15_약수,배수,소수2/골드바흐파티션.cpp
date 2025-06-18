#include <iostream>
#include <vector>
using namespace std;

vector<bool> isPrime(1000001, true);
void sieve()
{
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= 1'000'000; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= 1'000'000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    sieve();

    while (T--)
    {
        int n, cnt = 0;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            if (i > n - i)
                break; // To avoid double counting
            if (isPrime[i] && isPrime[n - i])
                cnt++; // Goldbach's conjecture
        }
        cout << cnt << '\n';
    }
}