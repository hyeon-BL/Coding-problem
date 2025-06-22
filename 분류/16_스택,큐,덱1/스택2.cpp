#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 명령의 수
    cin >> N;
    stack<int> st; // 스택 선언

    while (N--)
    {
        int command;
        cin >> command;

        if (command == 1)
        { // push 명령
            int x;
            cin >> x;
            st.push(x); // 스택에 x를 추가
        }
        else if (command == 2)
        { // pop 명령
            if (!st.empty())
            {
                cout << st.top() << '\n'; // 스택에서 가장 위의 원소를 출력
                st.pop();                 // 스택에서 가장 위의 원소를 제거
            }
            else
            {
                cout << -1 << '\n'; // 스택이 비어있으면 -1 출력
            }
        }
        else if (command == 3)
        {                              // size 명령
            cout << st.size() << '\n'; // 스택의 크기를 출력
        }
        else if (command == 4)
        {                                         // empty 명령
            cout << (st.empty() ? 1 : 0) << '\n'; // 스택이 비어있으면 1, 아니면 0 출력
        }
        else if (command == 5)
        { // top 명령
            if (!st.empty())
            {
                cout << st.top() << '\n'; // 스택의 가장 위 원소를 출력
            }
            else
            {
                cout << -1 << '\n'; // 스택이 비어있으면 -1 출력
            }
        }
    }
}