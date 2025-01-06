#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string octal;
    cin >> octal;

    string binary = "";
    string octal_to_binary[8] = {
        "000", "001", "010", "011", "100", "101", "110", "111"}; // 8진수 -> 2진수 변환

    for (int i = 0; i < octal.size(); ++i)
    {
        int digit = octal[i] - '0';
        if (i == 0)
        { // 첫 번째 숫자는 0이면 제거
            binary += to_string(stoi(octal_to_binary[digit]));
        }
        else
        { // 나머지 숫자는 0을 포함하여 변환
            binary += octal_to_binary[digit];
        }
    }

    cout << binary;

    return 0;
}