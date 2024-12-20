#include <iostream>
#include <queue>
using namespace std;

int bfs(int start_n, int end_n)
{
    queue<pair<long long, int>> q;
    q.push({start_n, 1});

    while (!q.empty())
    {
        long long num = q.front().first; // current number
        int steps = q.front().second;    // steps to reach num
        q.pop();

        if (num == end_n)
            return steps;

        if (num * 2 <= end_n)
        { // *2
            q.push({num * 2, steps + 1});
        }
        if (num * 10 + 1 <= end_n)
        { // *10 + 1
            q.push({num * 10 + 1, steps + 1});
        }
    }

    return -1;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int start_n, end_n;
    cin >> start_n >> end_n;

    cout << bfs(start_n, end_n);

    return 0;
}