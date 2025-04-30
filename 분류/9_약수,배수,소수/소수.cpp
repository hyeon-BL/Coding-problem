#include <iostream>
#include <vector>
using namespace std;

vector<bool> eratosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p])
        {
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    return prime;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M, N;
    cin >> M >> N;

    vector<bool> prime = eratosthenes(N);

    int sum = 0, temp;
    bool found = false;
    for (int i = M; i <= N; i++)
    {
        if (prime[i])
        {
            sum += i;
            if (!found)
            {
                temp = i;
                found = true;
            }
        }
    }
    if (found)
    {
        cout << sum << '\n'
             << temp;
    }
    else
    {
        cout << -1;
    }
}