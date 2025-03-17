#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct platform
{
    int y, x1, x2;

    bool operator<(const platform &p) const
    {
        return y < p.y;
    }
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // number of platforms
    cin >> N;

    vector<platform> platforms(N);
    for (int i = 0; i < N; i++)
    {
        cin >> platforms[i].y >> platforms[i].x1 >> platforms[i].x2;
    }

    sort(platforms.begin(), platforms.end());

    int ans = 0;

    for (int i = 0; i < N; i++)
    { // for each platform
        int left_pillar = platforms[i].y;
        int right_pillar = platforms[i].y;

        for (int j = 0; j < i; j++)
        {
            if (platforms[j].x1 <= platforms[i].x1 && platforms[i].x1 < platforms[j].x2)
            { // i-th platform is between j-th platform
                // left_pillar = height of the left pillar of the i-th platform
                left_pillar = platforms[i].y - platforms[j].y;
            }
        }

        for (int j = 0; j < i; j++)
        {
            if (platforms[j].x1 < platforms[i].x2 && platforms[i].x2 <= platforms[j].x2)
            { // i-th platform is between j-th platform
                // right_pillar = height of the right pillar of the i-th platform
                right_pillar = platforms[i].y - platforms[j].y;
            }
        }

        ans += left_pillar + right_pillar;
    }

    cout << ans;
}

/*
디버깅 과정
1. 경계에서 만나는 경우 -> 등호 제거
2. 같은 x에 여러 플랫폼이 있는 경우 -> 정렬을 통해 해결(break문 필요 없음)
3. 경계에서 만나는 경우 -> x1, x2가 같은 경우도 고려해야 함
*/