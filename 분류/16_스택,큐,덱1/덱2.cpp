#include <iostream>
#include <deque>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 명령의 수
    cin >> N;
    deque<int> dq; // 덱 선언
    while (N--)
    {
        int command;
        cin >> command;

        if (command == 1)
        {
            int x;
            cin >> x;
            dq.push_front(x); // 덱의 앞에 x를 추가
        }
        else if (command == 2)
        {
            int x;
            cin >> x;
            dq.push_back(x); // 덱의 뒤에 x를 추가
        }
        else if (command == 3)
        {
            if (!dq.empty())
            {
                cout << dq.front() << '\n'; // 덱의 앞 요소를 출력
                dq.pop_front();
            }
            else
            {
                cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
            }
        }
        else if (command == 4)
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n'; // 덱의 뒤 요소를 출력
                dq.pop_back();
            }
            else
            {
                cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
            }
        }
        else if (command == 5)
        {
            cout << dq.size() << '\n'; // 덱의 크기를 출력
        }
        else if (command == 6)
        {
            cout << (dq.empty() ? 1 : 0) << '\n'; // 덱이 비어있으면 1, 아니면 0 출력
        }
        else if (command == 7)
        {
            if (!dq.empty())
            {
                cout << dq.front() << '\n'; // 덱의 앞 요소를 출력
            }
            else
            {
                cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
            }
        }
        else if (command == 8)
        {
            if (!dq.empty())
            {
                cout << dq.back() << '\n'; // 덱의 뒤 요소를 출력
            }
            else
            {
                cout << -1 << '\n'; // 덱이 비어있으면 -1 출력
            }
        }
    }
}