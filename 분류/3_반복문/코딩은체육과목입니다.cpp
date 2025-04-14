#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N비트 정수
    cin >> N;

    int longcnt = N / 4; // 4비트씩 나누어지는 개수

    while (longcnt--)
    {
        cout << "long "; // long을 출력
    }
    cout << "int"; // 마지막에 int를 출력
}