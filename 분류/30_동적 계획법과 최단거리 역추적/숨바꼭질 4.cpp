#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> q;
    q.push({N, 0});
    vector<int> visited(100001, 0);
    vector<int> track(100001, -1);
    visited[N] = 1;

    while (!q.empty())
    {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();

        if (pos == K)
        {
            cout << time << '\n';
            break;
        }

        for (int next : {pos - 1, pos + 1, pos * 2})
        {
            if (next < 0 || next > 100000)
                continue;
            if (visited[next])
                continue;
            visited[next] = 1;
            track[next] = pos;
            q.push({next, time + 1});
        }
    }

    vector<int> result;
    for (int i = K; i != -1; i = track[i])
        result.push_back(i);

    reverse(result.begin(), result.end());

    for (int i : result)
        cout << i << " ";
    return 0;
}