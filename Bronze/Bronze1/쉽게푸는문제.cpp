#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int start, end, cnt = 0, n = 1;
    cin >> start >> end;

    vector<int> sequence(end + 1);
    sequence[0] = 0;
    for (int i = 1; i <= end; i++)
    {
        sequence[i] = sequence[i - 1] + n;
        cnt++;
        if (cnt == n)
        {
            cnt = 0;
            n++;
        }
    }
    cout << sequence[end] - sequence[start - 1];
}