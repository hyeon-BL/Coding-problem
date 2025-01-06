#include <iostream>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int S1, S2, S3;
    int max_freq = 0;
    int *freq = new int[81]();

    cin >> S1 >> S2 >> S3;

    for (int i = 1; i <= S1; ++i)
    {
        for (int j = 1; j <= S2; ++j)
        {
            for (int k = 1; k <= S3; ++k)
            {
                freq[i + j + k]++;
                max_freq = max(max_freq, freq[i + j + k]);
            }
        }
    }

    for (int i = 1; i <= 80; ++i)
    {
        if (freq[i] == max_freq)
        {
            cout << i;
            break;
        }
    }
}