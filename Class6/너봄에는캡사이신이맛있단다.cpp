#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long n;
    long long menu[300001];
    long long sqare[300001];
    long long MOD = 1'000'000'007;
    long long temp = 1;
    long long p = 0, m = 0;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> menu[i];
    }

    // 각 위치에서의 (2^i - 1) 값을 미리 계산
    for (int i = 0; i < n; i++)
    {
        sqare[i] = temp - 1;
        temp *= 2;
        temp %= MOD;
    }

    // 정렬하여 각 요소가 최댓값과 최솟값으로 사용되는 경우를 계산
    sort(menu, menu + n);

    // 각 요소가 최댓값으로 사용되는 경우의 합과
    // 최솟값으로 사용되는 경우의 합을 계산
    for (int i = n - 1; i >= 0; i--)
    {
        p += sqare[i] * menu[i];
        m += sqare[i] * menu[n - 1 - i];
        p %= MOD;
        m %= MOD;
    }

    // 최종 결과: (최댓값의 합 - 최솟값의 합)을 MOD로 나눈 나머지
    cout << ((p % MOD) + MOD - (m % MOD)) % MOD;

    return 0;
}