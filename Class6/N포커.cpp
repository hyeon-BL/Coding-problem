#include <iostream>
#include <vector>
using namespace std;

long long comb(int n, int k)
{ // nCk
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    long long res = 1;
    for (int i = 1; i <= k; ++i)
    { // nCk = n! / (k! * (n-k)!) = n * (n-1) * ... * (n-k+1) / k!
        res *= (n - i + 1);
        res /= i;
    }
    return res;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N; // N장 카드

    if (N < 4)
    {
        cout << 0;
        return 0;
    }

    if (N == 52)
    {
        cout << 1;
        return 0;
    }

    // 승리하는 경우의 수 (Four of a kind)
    // 1. i개의 포카드 (1 <= i <= 13)
    // 2. 선택한 숫자의 4장을 모두 가짐 (4C4 = 1)
    // 3. 나머지 N-(4*i)장의 카드를 선택 (52-4*i)C(N-4*i)
    // 4. 나머지 카드 중 포카드인 경우 제외 -> (-1)^i(포함 배제의 원리)
    long long res = 0;
    for (int i = 1; i <= N / 4; ++i)
    {
        if (i % 2 == 1)
            res = (res + comb(13, i) * comb(52 - 4 * i, N - 4 * i)) % 10'007;
        else
            res = (res - (comb(13, i) * comb(52 - 4 * i, N - 4 * i) % 10'007) + 10'007) % 10'007;
    }

    cout << res;

    return 0;
}