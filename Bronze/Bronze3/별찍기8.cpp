#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    int r = 1;

    for (int i = 1; i <= (2 * N - 1); i++)
    { // 2*N-1번째 줄까지 출력
        for (int j = 1; j <= (2 * N); j++)
        {
            if (j > r && j <= (2 * N - r))
            {
                cout << " ";
            }
            else
            {
                cout << "*";
            }
        }
        cout << "\n";
        if (i < N)
        {
            r++;
        }
        else
        {
            r--;
        }
    }
}