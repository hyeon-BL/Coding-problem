#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int W, H, X, Y, P;
    cin >> W >> H >> X >> Y >> P;

    int count = 0;
    for (int i = 0; i < P; ++i)
    {
        int px, py;
        cin >> px >> py;

        bool inside = false;

        // 직사각형 체크
        if (px >= X && px <= X + W && py >= Y && py <= Y + H)
        {
            inside = true;
        }
        else
        {
            // 왼쪽 원 체크
            int dx1 = px - X;
            int dy1 = py - (Y + H / 2);
            if (dx1 * dx1 + dy1 * dy1 <= (H / 2) * (H / 2))
                inside = true;
            else
            {
                // 오른쪽 원 체크
                int dx2 = px - (X + W);
                int dy2 = py - (Y + H / 2);
                if (dx2 * dx2 + dy2 * dy2 <= (H / 2) * (H / 2))
                    inside = true;
            }
        }

        if (inside)
            ++count;
    }
    cout << count << '\n';
}