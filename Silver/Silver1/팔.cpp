#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int L, R;
    cin >> L >> R;

    string str_L = to_string(L);
    string str_R = to_string(R);
    int min_eights = 0;

    if (str_L.size() != str_R.size())
    { // 길이가 다르면 맞춰주기
        str_L = string(str_R.size() - str_L.size(), '0') + str_L;
    }

    for (size_t i = 0; i < str_L.size(); i++)
    {
        if (str_L[i] != str_R[i])
        { // 다른 숫자가 나오면 종료 -> 뒷자리는 0으로 채울 수 있음
            break;
        }
        if (str_L[i] == '8')
        {
            min_eights++;
        }
    }

    cout << min_eights;
    return 0;
}