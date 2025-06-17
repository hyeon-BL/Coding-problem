#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    while (true)
    {
        long long N;
        cin >> N;
        if (N == 0)
        {
            break;
        }

        int count = 0;
        vector<bool> isPrime(2 * N + 1, true);
        isPrime[0] = isPrime[1] = false; // 0과 1은 소수가 아님

        for (long long i = 2; i * i <= 2 * N; ++i)
        {
            if (isPrime[i])
            {
                for (long long j = i * i; j <= 2 * N; j += i)
                {
                    isPrime[j] = false;
                }
            }
        }

        for (long long i = N + 1; i <= 2 * N; ++i)
        {
            if (isPrime[i])
            {
                count++;
            }
        }
        cout << count << "\n";
    }
}