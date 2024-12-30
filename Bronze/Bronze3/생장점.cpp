#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    while (true)
    {
        int N, cnt = 1;
        cin >> N;
        vector<int> branchorama(2 * N);

        if (N == 0)
            break;

        for (int i = 0; i < 2 * N; i++)
        {
            cin >> branchorama[i];
        }
        for (int i = 0; i < 2 * N; i++)
        {
            if (i % 2 == 0)
            {
                cnt *= branchorama[i];
            }
        }
        for (int i = 0; i < 2 * N; i++)
            if (i % 2 == 1)
            {
                if (branchorama[i] != 0)
                {
                    if (i == 2 * N - 1)
                    {
                        cnt -= branchorama[i];
                    }
                    else
                    {
                        int temp = 1;
                        for (int j = i + 1; j < 2 * N; j++)
                        {
                            if (j % 2 == 0)
                            {
                                temp *= branchorama[j];
                            }
                        }
                        cnt -= temp * branchorama[i];
                    }
                }
            }
        cout << cnt << "\n";
    }
}