#include <iostream>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N, cnt = 0;
    int num = 0;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (i == N - 1)
        {
            cnt += num;
        }
        else
        {
            cnt += num - 1;
        }
    }
    cout << cnt;
}