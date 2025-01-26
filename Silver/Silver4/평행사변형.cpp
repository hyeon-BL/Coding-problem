#include <iostream>
#include <cmath>
using namespace std;

struct dot
{
    int x, y;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    dot d[3];
    for (int i = 0; i < 3; i++)
    {
        cin >> d[i].x >> d[i].y;
    }

    int ccw = (d[1].x - d[0].x) * (d[2].y - d[0].y) - (d[1].y - d[0].y) * (d[2].x - d[0].x);
    if (ccw == 0)
        cout << -1;
    else
    {
        double cir_01 = sqrt(pow(d[0].x - d[1].x, 2) + pow(d[0].y - d[1].y, 2));
        double cir_02 = sqrt(pow(d[0].x - d[2].x, 2) + pow(d[0].y - d[2].y, 2));
        double cir_12 = sqrt(pow(d[1].x - d[2].x, 2) + pow(d[1].y - d[2].y, 2));

        double first = 2 * (cir_01 + cir_02);
        double second = 2 * (cir_01 + cir_12);
        double third = 2 * (cir_02 + cir_12);

        double max_p = max(first, max(second, third));
        double min_p = min(first, min(second, third));

        cout << fixed;
        cout.precision(10);
        cout << max_p - min_p;
    }
}