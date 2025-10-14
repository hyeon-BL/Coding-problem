#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int C, N;
    cin >> C;
    while (C--)
    {
        cin >> N;
        vector<int> v(N);

        double sum = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        sum /= N;

        sort(v.begin(), v.end());
        int cnt = N - (upper_bound(v.begin(), v.end(), sum) - v.begin());
        cout << fixed;
        cout.precision(3);
        cout << (double)cnt / N * 100 << "%\n";
    }
}