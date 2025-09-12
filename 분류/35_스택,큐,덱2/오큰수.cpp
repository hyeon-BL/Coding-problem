#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    stack<int> st;
    for (int i = 0; i < N; i++)
    {
        int elem;
        cin >> elem;
        st.push(elem);
    }

    stack<int> temp;
    vector<int> result;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        if (temp.empty())
        {
            result.push_back(-1);
            temp.push(top);
        }
        else
        {
            while (!temp.empty() && temp.top() <= top)
                temp.pop(); // top보다 작거나 같은 원소들은 모두 pop
            if (temp.empty())
                result.push_back(-1);
            else
                result.push_back(temp.top());
            temp.push(top); // 현재 원소를 temp에 push
        }
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';

    return 0;
}