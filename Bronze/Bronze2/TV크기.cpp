#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int D, H, W;
    cin >> D >> H >> W;

    double x = D / sqrt((H * H) + (W * W));
    cout << (int)(H * x) << ' ' << (int)(W * x);
}