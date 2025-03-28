#include <iostream>
#include <regex>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; // 테스트 케이스
    cin >> T;

    while (T--)
    {
        string s;
        cin >> s; // 문자열 입력

        // 정규 표현식으로 패턴 검사
        regex pattern("(100+1+|01)+"); // 100+1+ 또는 01+ 패턴
        if (regex_match(s, pattern))   // 패턴과 일치하는지 검사
        {
            cout << "YES\n"; // 패턴이 일치하면 YES 출력
        }
        else
        {
            cout << "NO\n"; // 패턴이 일치하지 않으면 NO 출력
        }
    }

    return 0;
}
