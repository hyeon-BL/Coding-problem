#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string digit_1, digit_2;
    string result = "";

    cin >> digit_1 >> digit_2;

    int carry = 0;
    int i = digit_1.size() - 1;
    int j = digit_2.size() - 1;

    while (i >= 0 || j >= 0 || carry)
    {
        int sum = carry;
        if (i >= 0)
            sum += digit_1[i--] - '0';
        if (j >= 0)
            sum += digit_2[j--] - '0';

        carry = sum / 2;
        result += to_string(sum % 2);
    }

    bool is_zero = true;
    for (int i = result.size() - 1; i >= 0; --i)
    {
        if (result[i] != '0')
            is_zero = false;

        if (!is_zero)
            cout << result[i];
    }

    if (is_zero)
        cout << 0;
}