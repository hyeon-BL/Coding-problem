#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int P, M;
    cin >> P >> M;
    int S1, S2;
    S1 = (P + M) / 2;
    S2 = P - S1;
    if (S1 >= 0 && S2 >= 0 && S1 + S2 == P && S1 - S2 == M)
    {
        cout << S1 << ' ' << S2;
    }
    else
        cout << -1;
}