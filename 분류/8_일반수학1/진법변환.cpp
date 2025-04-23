#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string N;
    cin >> N;
    int B;
    cin >> B;

    int ans = 0;
    for (int i = 0; i < N.size(); i++)
    {
        if (N[i] >= 'A')
        { // 10 ~ 35
            ans += (N[i] - 'A' + 10) * pow(B, N.size() - i - 1);
        }
        else
        { // 0 ~ 9
            ans += (N[i] - '0') * pow(B, N.size() - i - 1);
        }
    }

    cout << ans;
}