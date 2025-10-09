#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    if (T == 1)
    {
        // 갑의 역할: A, B를 받아서 26진법 문자열 생성
        unsigned long long A, B;
        cin >> A >> B;
        unsigned long long sum = A + B;

        string s = "";
        for (int i = 0; i < 13; ++i)
        {
            s += (char)('a' + (sum % 26));
            sum /= 26;
        }
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
    else
    {
        // 을의 역할: 26진법 문자열을 받아서 A+B 복원
        string s;
        cin >> s;
        unsigned long long sum = 0;
        for (char c : s)
        {
            sum *= 26;
            sum += (c - 'a');
        }
        cout << sum << endl;
    }
    return 0;
}
