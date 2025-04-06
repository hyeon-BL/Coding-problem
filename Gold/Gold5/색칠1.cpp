#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int w, h, f, c, x1, y1, x2, y2;
    cin >> w >> h >> f >> c >> x1 >> y1 >> x2 >> y2;

    // 전체 종이의 면적 계산
    long long total_area = (long long)w * (long long)h;

    // 종이를 가로로 나눈 구간의 개수
    long long vertical_area = c + 1;

    // 색칠된 직사각형의 면적 계산
    long long painted_square = (long long)(x2 - x1) * (long long)(y2 - y1);

    // 색칠된 면적을 저장하기 위한 변수
    long long painted_area;

    // 접힌 위치가 오른쪽 부분이 더 크거나 같을 때
    if (w - f >= f)
    {
        // 접힌 위치가 직사각형 내부에 걸쳐 있을 때
        if (f >= x1 && f <= x2)
        { // (f - x1) * (y2 - y1)만큼 색칠된 면적이 추가됨
            painted_area = ((long long)(f - x1) * (long long)(y2 - y1) + painted_square) * vertical_area;
            cout << total_area - painted_area;
        }
        // 접힌 위치가 직사각형의 왼쪽에 있을 때
        else if (f <= x1)
        {
            painted_area = (painted_square * vertical_area);
            cout << total_area - painted_area;
        }
        // 접힌 위치가 직사각형의 오른쪽에 있을 때
        else if (x2 <= f)
        { // 2배의 면적이 색칠됨
            painted_area = (2 * (painted_square * vertical_area));
            cout << total_area - painted_area;
        }
    }
    // 접힌 위치가 왼쪽 부분이 더 클 때
    else
    {
        // 접힌 위치가 직사각형 내부에 걸쳐 있을 때
        if (x1 <= w - f && x2 >= w - f)
        { // ((w - f) - x1) * (y2 - y1)만큼 색칠된 면적이 추가됨
            painted_area = ((long long)((w - f) - x1) * (long long)(y2 - y1) + painted_square) * vertical_area;
            cout << total_area - painted_area;
        }
        // 접힌 위치가 직사각형의 오른쪽에 있을 때
        else if (x1 >= w - f)
        {
            painted_area = (painted_square * vertical_area);
            cout << total_area - painted_area;
        }
        // 접힌 위치가 직사각형의 왼쪽에 있을 때
        else if (x2 <= w - f)
        { // 2배의 면적이 색칠됨
            painted_area = (2 * (painted_square * vertical_area));
            cout << total_area - painted_area;
        }
    }

    return 0;
}