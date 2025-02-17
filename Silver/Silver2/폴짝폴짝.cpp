#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 징검다리 수
    cin >> N;
    vector<int> stones(N); // stones: 배수
    for (int i = 0; i < N; i++)
    {
        cin >> stones[i];
    }
    int a, b; // a: 시작점, b: 도착점
    cin >> a >> b;

    vector<bool> visited(N, false);
    queue<pair<int, int>> q; // pair<current position, steps>
    q.push({a - 1, 0});
    visited[a - 1] = true;

    while (!q.empty())
    {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == b - 1)
        {
            cout << steps;
            return 0;
        }

        for (int i = current + stones[current]; i < N; i += stones[current])
        { // i: current + stones[current], current + 2 * stones[current] ...
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, steps + 1});
            }
        }

        for (int i = current - stones[current]; i >= 0; i -= stones[current])
        { // i: current - stones[current], current - 2 * stones[current] ...
            if (!visited[i])
            {
                visited[i] = true;
                q.push({i, steps + 1});
            }
        }
    }

    cout << -1;
    return 0;
}