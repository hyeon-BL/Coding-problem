#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map> // ordered_map의 경우 O(log n), unordered_map의 경우 O(1) => ordered_map 사용 시 시간 초과
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    stack<int> st;
    unordered_map<int, int> countMap; // 각 원소의 개수를 저장하는 맵
    for (int i = 0; i < N; i++)
    {
        int elem;
        cin >> elem;
        st.push(elem);
        countMap[elem]++; // 원소의 개수 증가
    }

    stack<pair<int, int>> temp; // (원소, 개수)
    vector<int> result;
    while (!st.empty())
    {
        int top = st.top();
        int count = countMap[top];
        st.pop();
        if (temp.empty())
        {
            result.push_back(-1);
            temp.push({top, count});
        }
        else
        {
            while (!temp.empty() && temp.top().second <= count)
                temp.pop(); // top의 개수보다 작거나 같은 원소들은 모두 pop

            if (temp.empty())
                result.push_back(-1);
            else
                result.push_back(temp.top().first);
            temp.push({top, count}); // 현재 원소와 개수를 temp에 push
        }
    }

    for (int i = result.size() - 1; i >= 0; i--)
        cout << result[i] << ' ';

    return 0;
}