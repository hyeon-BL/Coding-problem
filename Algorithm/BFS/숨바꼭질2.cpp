#include <iostream>
#include <queue>
using namespace std;

pair<int, int> bfs(int start_n, int end_n)
{
    bool visited[100001] = {false}; // 중복 탐색 방지(메모리, 시간 절약)
    queue<pair<long long, int>> q;
    q.push({start_n, 0});

    int min_steps = 9999999;
    int ways = 0;

    while (!q.empty())
    {
        long long num = q.front().first; // current number
        int steps = q.front().second;    // steps to reach num
        q.pop();

        visited[num] = true;

        if (min_steps < steps) // 1000000 이상의 수는 무시
            continue;

        if (num == end_n)
        {
            min_steps = steps;
            ways++;
            continue;
        }

        if (num * 2 <= 100000 && !visited[num * 2])
        {                                 // *2
            q.push({num * 2, steps + 1}); // 0초 후 이동
        }
        if (num + 1 <= 100000 && !visited[num + 1])
        {                                 // + 1
            q.push({num + 1, steps + 1}); // 1초 후 이동
        }
        if (num - 1 >= 0 && !visited[num - 1])
        {                                 // - 1
            q.push({num - 1, steps + 1}); // 1초 후 이동
        }
    }

    return make_pair(min_steps, ways);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int start_n, end_n;
    cin >> start_n >> end_n;

    cout << bfs(start_n, end_n).first << '\n'
         << bfs(start_n, end_n).second;

    return 0;
}