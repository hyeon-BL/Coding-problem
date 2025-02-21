#include <iostream>
#include <string>
using namespace std;

bool Overlap(const string &first, const string &second, int offset)
{ // 두 기어가 겹치는지 확인
    int len1 = first.size();
    int len2 = second.size();
    for (int i = 0; i < len2; i++)
    {
        if (offset + i >= 0 && offset + i < len1)
        {
            if (first[offset + i] == '2' && second[i] == '2')
            { // 이와 이가 만나면 안 됨
                return false;
            }
        }
    }
    return true;
}

int Kickdown_length(const string &first, const string &second)
{
    int len1 = first.size();
    int len2 = second.size();
    int minLength = len1 + len2; // 최대 길이

    for (int offset = -len2 + 1; offset < len1; offset++)
    {
        if (Overlap(first, second, offset))
        { // 기어가 맞물릴 때
            int combinedLength = max(len1, offset + len2) - min(0, offset);
            minLength = min(minLength, combinedLength);
        }
    }

    return minLength;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string first_gear, second_gear;
    cin >> first_gear >> second_gear;

    int result = Kickdown_length(first_gear, second_gear);
    cout << result;

    return 0;
}