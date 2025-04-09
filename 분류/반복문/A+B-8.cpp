#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T; // 테스트 케이스 수
    int temp = T;
    while (T--)
    {
        int A, B;
        cin >> A >> B;                                                                     // A와 B 입력
        cout << "Case #" << temp - T << ": " << A << " + " << B << " = " << A + B << '\n'; // A와 B의 합 출력
    }
}