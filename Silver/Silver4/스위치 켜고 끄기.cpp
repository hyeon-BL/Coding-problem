#include <iostream>
#include <vector>
using namespace std;

void girl(vector<int> &status, int idx)
{
    int start = idx - 1;
    int end = idx + 1;

    status[idx] = 1 - status[idx];
    while (start >= 1 && end < status.size())
    {
        if (status[start] == status[end])
        {
            status[start] = 1 - status[start];
            status[end] = 1 - status[end];
            start--;
            end++;
        }
        else
            break;
    }
}

void boy(vector<int> &status, int idx)
{
    for (int i = idx; i < status.size(); i += idx)
        status[i] = 1 - status[i];
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<int> status(N + 1, 0);
    for (int i = 1; i <= N; i++)
        cin >> status[i];

    int students;
    cin >> students;

    for (int i = 0; i < students; i++)
    {
        int gender, idx;
        cin >> gender >> idx;
        if (gender == 1)
            boy(status, idx);
        else
            girl(status, idx);
    }

    for (int i = 1; i <= N; i++)
    {
        cout << status[i] << ' ';
        if (i % 20 == 0)
            cout << '\n';
    }
}