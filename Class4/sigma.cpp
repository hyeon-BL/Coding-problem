#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

using ll = long long;
const ll MOD = 1'000'000'007;

ll modInverse(ll x, ll y)
{
    if (y == 1)
        return x;
    if (y % 2 == 1)
        return x * modInverse(x, y - 1) % MOD;
    ll p = modInverse(x, y / 2);
    return p * p % MOD;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll m, a, b;
    ll ans = 0;

    cin >> m;

    while (m--)
    {
        cin >> b >> a;
        ll g = gcd(a, b);
        b /= g;
        a /= g;
        ans = (ans + a * modInverse(b, MOD - 2) % MOD) % MOD;
    }

    cout << ans;

    return 0;
}