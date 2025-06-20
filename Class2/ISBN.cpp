#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string isbn;
    cin >> isbn;

    int sum = 0;
    bool even = true; // 짝수 인덱스 여부
    for (int i = 0; i < 13; i++)
    {
        if (isbn[i] == '*')
        {
            if (i % 2 == 0)
                even = true;
            else
                even = false;
            continue; // '*'는 건너뜀
        }
        if (i % 2 == 0)
        {
            sum += isbn[i] - '0'; // 짝수 인덱스는 그대로 더함
        }
        else
        {
            sum += (isbn[i] - '0') * 3; // 홀수 인덱스는 3배로 더함
        }
    }

    int check_digit = 0; // 체크 디지털 초기화
    if (even)
    {
        check_digit = (10 - (sum % 10)) % 10; // 짝수 인덱스일 때 체크 디지털 계산
    }
    else
    {
        // 3x ≡ (10 - sum % 10) (mod 10)를 만족하는 x 찾기
        int target = (10 - sum % 10) % 10;

        // 3의 모듈로 10에서의 역원을 이용 (3 * 7 ≡ 1 (mod 10))
        check_digit = (target * 7) % 10;
    }
    cout << check_digit << "\n"; // 결과 출력
    return 0;
}