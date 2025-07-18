#include <iostream>
using namespace std;

int value[21][21][21] = {0}; // w(a, b, c) 값을 저장할 3차원 배열

void init()
{
    for (int i = 0; i <= 20; i++)
    {
        for (int j = 0; j <= 20; j++)
        {
            for (int k = 0; k <= 20; k++)
            {
                if (i == 0 || j == 0 || k == 0)
                {
                    value[i][j][k] = 1; // w(0, b, c) = w(a, 0, c) = w(a, b, 0) = 1
                }
                else if (i < j && j < k)
                {
                    value[i][j][k] = value[i][j][k - 1] + value[i][j - 1][k - 1] - value[i][j - 1][k];
                }
                else
                {
                    value[i][j][k] = value[i - 1][j][k] + value[i - 1][j - 1][k] + value[i - 1][j][k - 1] - value[i - 1][j - 1][k - 1];
                }
            }
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    init(); // value 배열 초기화
    while (true)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;

        if (a <= 0 || b <= 0 || c <= 0)
            cout << "w(" << a << ", " << b << ", " << c << ") = 1\n";
        else if (a > 20 || b > 20 || c > 20)
            cout << "w(" << a << ", " << b << ", " << c << ") = " << value[20][20][20] << "\n";
        else
            cout << "w(" << a << ", " << b << ", " << c << ") = " << value[a][b][c] << "\n";
    }
}