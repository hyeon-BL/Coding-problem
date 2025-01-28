#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N: 큐의 크기, M: 찾으려는 수의 개수
    int total = 0;
    cin >> N >> M;

    deque<int> dq;
    for (int i = 1; i <= N; i++)
    {
        dq.push_back(i);
    }

    for (int i = 0; i < M; i++)
    {
        int target;
        cin >> target;

        int cnt = 0;
        while (1)
        {
            if (dq.front() == target)
            { // 찾으려는 수를 찾은 경우
                dq.pop_front();
                break;
            }
            if (dq.size() / 2 >= distance(dq.begin(), find(dq.begin(), dq.end(), target)))
            { // 찾으려는 수가 앞쪽에 가까운 경우
                dq.push_back(dq.front());
                dq.pop_front();
            }
            else
            { // 찾으려는 수가 뒷쪽에 가까운 경우
                dq.push_front(dq.back());
                dq.pop_back();
            }
            cnt++;
        }
        total += cnt;
    }
    cout << total;
}