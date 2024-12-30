#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int main(void)
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    string P; // 10^100 -> can't use long long(up to 10^63)
    int K;
    cin >> P >> K;
    vector<int> arr(K + 1);

    arr[0] = arr[1] = 1;
    for (int i = 2; i <= K; i++)
    {
        arr[i] = 0;
    }

    for (int i = 2; i <= sqrt(K); i++)
    {
        if (arr[i])
            continue; // not prime
        for (int j = i * 2; j <= K; j += i)
        {
            arr[j] = 1; // not prime
        }
    }

    for (int i = 2; i < K; i++)
    {
        if (!arr[i]) // prime
        {
            int res = 0;
            for (int j = 0; j < P.length(); j++)
            {
                res = (res * 10 + P[j] - '0') % i;
            }
            if (!res)
            { // divisible by prime
                cout << "BAD " << i;
                return 0;
            }
        }
    }
    cout << "GOOD";
    return 0;
}