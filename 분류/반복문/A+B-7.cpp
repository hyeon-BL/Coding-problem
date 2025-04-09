#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T; // 테스트 케이스 수
    for (int i = 1; i <= T; i++)
    {
        int A, B;
        cin >> A >> B;
        cout << "Case #" << i << ": " << A + B << '\n'; // A와 B의 합 출력
    }
}