#include <iostream>
#include <queue>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 명령의 수
    cin >> N;

    queue<int> q; // 큐 선언
    while (N--)
    {
        string command;
        cin >> command;

        if (command == "push")
        {
            int x;
            cin >> x;
            q.push(x); // 큐에 x를 추가
        }
        else if (command == "pop")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n'; // 큐의 앞 요소를 출력
                q.pop();
            }
            else
            {
                cout << -1 << '\n'; // 큐가 비어있으면 -1 출력
            }
        }
        else if (command == "size")
        {
            cout << q.size() << '\n';
        }
        else if (command == "empty")
        {
            cout << (q.empty() ? 1 : 0) << '\n';
        }
        else if (command == "front")
        {
            if (!q.empty())
            {
                cout << q.front() << '\n'; // 큐의 앞 요소 출력
            }
            else
            {
                cout << -1 << '\n'; // 큐가 비어있으면 -1 출력
            }
        }
        else if (command == "back")
        {
            if (!q.empty())
            {
                cout << q.back() << '\n'; // 큐의 뒤 요소 출력
            }
            else
            {
                cout << -1 << '\n'; // 큐가 비어있으면 -1 출력
            }
        }
    }
}