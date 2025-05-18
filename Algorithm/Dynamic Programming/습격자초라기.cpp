#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;                 // N: 구역의 개수 / 2, W: 특수 소대원 수
vector<int> inner, outer; // inner: 안쪽 구역, outer: 바깥쪽 구역
vector<int> a;            // a[i]: 안쪽, 바깥쪽 모두 i-1까지
vector<int> b;            // b[i]: 안쪽은 i까지, 바깥쪽은 i-1까지
vector<int> c;            // c[i]: 안쪽은 i-1까지, 바깥쪽은 i까지

void recurrence_relation(int s)
{
    // DP 점화식
    for (int i = s; i < N; i++)
    {
        a[i + 1] = min(b[i] + 1, c[i] + 1);
        if (inner[i] + outer[i] <= W)
        {
            a[i + 1] = min(a[i + 1], a[i] + 1);
        }
        if (i > 0 && (inner[i] + inner[i - 1] <= W) && (outer[i] + outer[i - 1] <= W))
        {
            a[i + 1] = min(a[i + 1], a[i - 1] + 2);
        }
        if (i < N - 1)
        {
            b[i + 1] = a[i + 1] + 1;
            if (inner[i] + inner[i + 1] <= W)
            {
                b[i + 1] = min(b[i + 1], c[i] + 1);
            }

            c[i + 1] = a[i + 1] + 1;
            if (outer[i] + outer[i + 1] <= W)
            {
                c[i + 1] = min(c[i + 1], b[i] + 1);
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; // 테스트 케이스 수
    cin >> T;

    while (T--)
    {
        cin >> N >> W;

        inner.resize(N + 1);
        outer.resize(N + 1);
        for (int i = 0; i < N; i++)
        {
            cin >> inner[i];
        }
        for (int i = 0; i < N; i++)
        {
            cin >> outer[i];
        }

        // DP 배열 초기화
        a.resize(N + 1, 0);
        b.resize(N + 1, 0);
        c.resize(N + 1, 0);

        // DP 점화식 호출
        a[0] = 0;
        b[0] = 1;
        c[0] = 1;
        recurrence_relation(0);

        int ans = a[N]; // 최솟값 (0, N-1 구역을 고려하지 않을 때)

        // 0, N-1 구역을 고려할 때(원형 구역)
        if (N > 1 && (inner[0] + inner[N - 1] <= W))
        {
            a[1] = 1;
            b[1] = 2;
            if (outer[0] + outer[1] <= W)
                c[1] = 1;
            else
                c[1] = 2;
            recurrence_relation(1);
            ans = min(ans, c[N - 1] + 1);
        }

        if (N > 1 && (outer[0] + outer[N - 1] <= W))
        {
            a[1] = 1;
            c[1] = 2;
            if (inner[0] + inner[1] <= W)
                b[1] = 1;
            else
                b[1] = 2;
            recurrence_relation(1);
            ans = min(ans, b[N - 1] + 1);
        }

        if (N > 1 && (inner[0] + inner[N - 1] <= W) && (outer[0] + outer[N - 1] <= W))
        {
            a[1] = 0;
            b[1] = 1;
            c[1] = 1;
            recurrence_relation(1);
            ans = min(ans, a[N - 1] + 2);
        }

        // 결과 출력
        cout << ans << '\n';
    }

    return 0;
}

/*
1
7 3
2 3 1 3 2 2 1
1 2 1 2 3 1 3

a = [0 1 3 4 6 8 9 11]
b = [1 2 4 5 7 9 10 0]
c = [1 2 3 5 7 9 10 0]


0, 1, 2, 3, 5, 7, 8, 10
1, 2, 3, 4, 6, 8, 9
1, 1, 3, 4, 6, 8, 9

ans = 10


1
5 6
3 3 5 5 3
1 3 4 1 4

ans = 6


reference: https://casterian.net/ps/boj1006/
*/