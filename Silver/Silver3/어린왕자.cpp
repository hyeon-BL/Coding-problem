#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct planet
{
    int x, y, r;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;

    while (T--)
    {
        int x1, y1, x2, y2, n;
        cin >> x1 >> y1 >> x2 >> y2; // 어린왕자(출발점), 장미(도착점)
        cin >> n;                    // 행성계의 개수
        vector<planet> planets(n);
        for (int i = 0; i < n; i++)
        {
            cin >> planets[i].x >> planets[i].y >> planets[i].r;
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            double dist1 = sqrt(pow(x1 - planets[i].x, 2) + pow(y1 - planets[i].y, 2));
            double dist2 = sqrt(pow(x2 - planets[i].x, 2) + pow(y2 - planets[i].y, 2));
            if (dist1 < planets[i].r && dist2 > planets[i].r)
                cnt++; // 어린왕자가 행성계 내부에 있고 장미가 외부에 있을 때
            else if (dist1 > planets[i].r && dist2 < planets[i].r)
                cnt++; // 어린왕자가 행성계 외부에 있고 장미가 내부에 있을 때
        }
        cout << cnt << '\n';
    }
}