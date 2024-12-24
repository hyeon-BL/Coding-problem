#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
bool visit[100001];

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    pq.push(make_pair(0, n));

    while (!pq.empty())
    {
        int time = pq.top().first;
        int x = pq.top().second;
        pq.pop();

        visit[x] = 1;

        if (x == k)
        {
            cout << time;
            break;
        }

        if (x - 1 >= 0 && !visit[x - 1])
            pq.push(make_pair(time + 1, x - 1));
        if (x + 1 <= 100000 && !visit[x + 1])
            pq.push(make_pair(time + 1, x + 1));
        if (x * 2 <= 100000 && !visit[x * 2])
            pq.push(make_pair(time, x * 2));
    }

    return 0;
}

/*
0 or 1의 가중치를 갖음
-> 일반적인 BFS로 풀 수 없음
-> 우선순위 큐를 이용한 다익스트라 알고리즘으로 풀어야 함

#include <iostream>
using namespace std;

#include <iostream>
#include <queue>
using namespace std;

int bfs(int start_n, int end_n)
{
    queue<pair<long long, int>> q;
    q.push({start_n, 0});

    while (!q.empty())
    {
        long long num = q.front().first; // current number
        int steps = q.front().second;    // steps to reach num
        q.pop();

        if (num == end_n)
            return steps;

        if (num * 2 <= end_n)
        {                             // *2
            q.push({num * 2, steps}); // 0초 후 이동
        }
        if (num + 1 <= end_n)
        {                                 // + 1
            q.push({num + 1, steps + 1}); // 1초 후 이동
        }
        if (num - 1 >= 0)
        {                                 // - 1
            q.push({num - 1, steps + 1}); // 1초 후 이동
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
*/