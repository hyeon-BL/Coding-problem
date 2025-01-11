#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<pair<int, int>> dot(N);

    for (int i = 0; i < N; i++)
    {
        cin >> dot[i].first >> dot[i].second;
    }

    long long area = 0;
    for (int i = 0; i < N; i++)
    {                        // 신발끈 공식 -> 외적을 이용한 다각형 넓이(삼각형 넓이 합) 구하기
        int j = (i + 1) % N; // 다각형의 마지막 점일 경우 첫 번째 점과 연결
        area += (long long)dot[i].first * dot[j].second;
        area -= (long long)dot[i].second * dot[j].first;
    }

    area = abs(area);
    cout << fixed;
    cout.precision(1);
    cout << area / 2.0;

    return 0;
}