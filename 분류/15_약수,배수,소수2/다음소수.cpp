#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        long long N;
        cin >> N;

        if (N < 2)
        {
            cout << "2\n";
            continue;
        }
        while (true)
        {
            bool isPrime = true;
            for (long long i = 2; i * i <= N; i++)
            {
                if (N % i == 0)
                {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime)
            {
                cout << N << "\n";
                break;
            }
            N++;
        }
    }
}