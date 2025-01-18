#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    while (T--)
    {
        int dist1[3], dist2[3];
        for (int i = 0; i < 6; i++)
        {
            if (i < 3)
                cin >> dist1[i];
            else
                cin >> dist2[i - 3];
        }

        double jb_dist = sqrt(pow(dist1[0] - dist2[0], 2) + pow(dist1[1] - dist2[1], 2));
        double jb_r = dist1[2] + dist2[2];
        double jb_r2 = dist1[2] > dist2[2] ? dist1[2] - dist2[2] : dist2[2] - dist1[2];

        if (jb_dist == 0)
        {
            if (dist1[2] == dist2[2])
                cout << -1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (jb_dist == jb_r || jb_dist == jb_r2)
            cout << 1 << '\n';
        else if (jb_dist < jb_r && jb_dist > jb_r2)
            cout << 2 << '\n';
        else
            cout << 0 << '\n';
    }
}