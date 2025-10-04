#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int nums[10001] = {
        0,
    };
    bool isSelfNum[10001] = {
        false,
    };
    for (int i = 1; i <= 10000; i++)
    {
        int n = i;
        while (n > 0)
        {
            nums[i] += n % 10;
            n /= 10;
        }
    }

    for (int i = 1; i <= 10000; i++)
    {
        int make = nums[i];
        if (i + make <= 10000)
        {
            isSelfNum[i + make] = true;
        }
    }

    for (int i = 1; i <= 10000; i++)
    {
        if (!isSelfNum[i])
        {
            cout << i << '\n';
        }
    }
}