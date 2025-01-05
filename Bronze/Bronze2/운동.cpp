#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, m, M, T, R;
    cin >> N >> m >> M >> T >> R;

    int X = m;    // 운동 시작 시 맥박
    int time = 0; // 운동 시간

    if (X + T > M)
    { // 운동 못함
        cout << -1;
        return 0;
    }

    while (N)
    {
        if (X + T <= M)
        { // 운동 가능
            X += T;
            N--;
        }
        else
        { // 휴식
            X = max(m, X - R);
        }
        time++;
    }

    cout << time;
}