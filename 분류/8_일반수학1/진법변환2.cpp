#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, B;
    cin >> N >> B;

    string ans = "";
    while (N > 0)
    {
        int r = N % B;
        if (r >= 10)
            ans += (char)(r - 10 + 'A');
        else
            ans += (char)(r + '0');
        N /= B;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}

/*
알고리즘 설명
1. N을 B로 나눈 나머지를 구한다.
2. 나머지가 10 이상이면 A, B, C, D, E, F로 변환한다.
3. 나머지가 10 미만이면 0~9로 변환한다.
4. N을 B로 나눈 몫을 구한다.
5. N이 0이 될 때까지 1~4를 반복한다.
6. 변환된 값을 역순으로 출력한다.
*/