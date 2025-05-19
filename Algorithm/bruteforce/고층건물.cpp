#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 빌딩의 수
    cin >> N;
    vector<int> building(N);
    for (int i = 0; i < N; i++)
    {
        cin >> building[i];
    }

    int maxVisible = 0; // 가장 많은 빌딩을 볼 수 있는 빌딩의 수

    for (int i = 0; i < N; i++)
    {
        int visibleCount = 0;

        // 왼쪽 빌딩 탐색
        long long dy1 = LLONG_MAX, dx1 = 1; // 이전 기울기의 분자와 분모
        for (int j = i - 1; j >= 0; j--)
        {
            long long dy2 = (long long)(building[i] - building[j]);
            long long dx2 = (long long)(i - j);
            if (dy1 * dx2 > dy2 * dx1)
            { // 기울기가 단조 감소
                visibleCount++;
                dy1 = dy2;
                dx1 = dx2;
            }
        }

        // 오른쪽 빌딩 탐색
        dy1 = LLONG_MIN, dx1 = 1; // 이전 기울기의 분자와 분모
        for (int j = i + 1; j < N; j++)
        {
            long long dy2 = (long long)(building[j] - building[i]);
            long long dx2 = (long long)(j - i);
            if (dy1 * dx2 < dy2 * dx1)
            { // 기울기가 단조 증가
                visibleCount++;
                dy1 = dy2;
                dx1 = dx2;
            }
        }

        // 최대값 갱신
        maxVisible = max(maxVisible, visibleCount);
    }

    cout << maxVisible << '\n';
    return 0;
}