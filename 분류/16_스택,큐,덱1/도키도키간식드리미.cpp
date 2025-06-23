#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 승환이 앞에 서있는 학생 수
    cin >> N;
    queue<int> line;
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        line.push(x); // 학생 번호를 큐에 추가
    }

    for (int num = 1; num <= N; num++)
    {
        if (!line.empty() && line.front() == num)
        {
            line.pop(); // 큐의 앞에 있는 학생이 현재 번호와 같으면 큐에서 제거
        }
        else if (!st.empty() && st.top() == num)
        {
            st.pop(); // 스택의 가장 위 학생이 현재 번호와 같으면 스택에서 제거
        }
        else
        {
            while (!line.empty() && line.front() != num)
            {
                st.push(line.front()); // 큐의 앞에 있는 학생이 현재 번호와 다르면 스택에 추가
                line.pop();            // 큐에서 제거
            }
            if (!line.empty() && line.front() == num)
            {
                line.pop(); // 큐의 앞에 있는 학생이 현재 번호와 같으면 큐에서 제거
            }
            else if (!st.empty() && st.top() == num)
            {
                st.pop(); // 스택의 가장 위 학생이 현재 번호와 같으면 스택에서 제거
            }
            else
            {
                cout << "Sad" << '\n'; // 현재 번호와 일치하는 학생을 찾지 못하면 "Sad" 출력
                return 0;
            }
        }
    }

    if (line.empty() && st.empty())
    {
        cout << "Nice" << '\n'; // 모든 학생이 올바른 순서로 서 있으면 "Nice" 출력
    }
    else
    {
        cout << "Sad" << '\n'; // 그렇지 않으면 "Sad" 출력
    }
    return 0;
}