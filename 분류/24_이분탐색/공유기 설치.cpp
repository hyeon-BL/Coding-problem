#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, C;
    cin >> N >> C;

    vector<int> coor(N);
    for (int i = 0; i < N; i++)
        cin >> coor[i];

    sort(coor.begin(), coor.end());

    int left = 1, right = coor[N - 1] - coor[0];
    int answer = 0;
    while (left <= right)
    { // 최대 거리를 찾는 이분 탐색
        int mid = (left + right) / 2;
        int count = 1, last = coor[0]; // 시작점은 무조건 설치

        for (int i = 1; i < N; i++)
        {
            if (coor[i] - last >= mid)
            { // 현재 설치된 공유기와의 거리가 mid 이상인 경우 - 공유기 설치
                count++;
                last = coor[i];
            }
        }

        if (count >= C)
        { // C개 이상의 공유기를 설치할 수 있는 경우 - 거리 늘리기
            answer = mid;
            left = mid + 1;
        }
        else
        { // C개 미만인 경우 - 거리 줄이기
            right = mid - 1;
        }
    }

    cout << answer << "\n";
    return 0;
}

/*
매개변수 이분 탐색을 이용하여 C개의 공유기를 설치할 수 있는 최대 거리를 찾는 문제
https://m42-orion.tistory.com/70
*/