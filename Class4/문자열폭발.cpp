#include <iostream>
#include <string>
using namespace std;

/*
문자열 폭발
1. 문자열에서 폭발 문자열이 있는 부분을 모두 폭발시킨다.
2. 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.

풀이
1. 문자열을 순회하며 스택에 문자를 하나씩 넣는다.
2. 스택의 크기가 폭발 문자열의 길이와 같을 때마다 폭발 문자열이 있는지 확인한다.

시간복잡도
O(N)

폭발 문자열이 없을 때까지 반복하므로 스택을 사용한다.
같은 문자를 두 개 이상 포함하지 않으므로 스택을 이용(패턴 매칭은 불필요)
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    string text;    // 전체 문자열 변수
    string pattern; // 폭발 문자열 변수
    string t = "";  // 임시 문자열

    getline(cin, text);    // 전체 문자열 입력
    getline(cin, pattern); // 폭발 문자열 입력

    int text_len = text.length();
    int pattern_len = pattern.length();

    for (int i = 0; i < text.length(); i++)
    {
        t += text[i]; // 문자 추가

        if (t.length() >= pattern_len)
        {                      // 임시 문자 길이가 폭발 문자열 보다 크거나 같을 때
            bool match = true; // 폭발 문자열 있는지 확인

            for (int j = 0; j < pattern_len; j++)
            {
                if (t[t.length() - pattern_len + j] != pattern[j])
                {
                    match = false;
                    break;
                } // t뒤에서 폭발 문자열 길이만큼 비교
            }

            if (match) // 폭발 문자열일 경우 삭제
                t.erase(t.end() - pattern_len, t.end());
        }
    }
    if (t.empty()) // 남아 있는 문자열이 없는 경우
        cout << "FRULA";
    else
        cout << t;
    return 0;
}