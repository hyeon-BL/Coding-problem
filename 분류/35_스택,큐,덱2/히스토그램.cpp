#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> heights(N);
    for (int i = 0; i < N; i++)
        cin >> heights[i];

    stack<int> s; // 인덱스를 저장하는 스택
    int max_area = 0;

    for (int i = 0; i < N; i++)
    {
        while (!s.empty() && heights[s.top()] > heights[i])
        { // 현재 막대보다 높은 막대가 있으면 넓이 계산
            int h = heights[s.top()];
            s.pop();
            int w = s.empty() ? i : i - s.top() - 1;
            max_area = max(max_area, h * w);
        }
        s.push(i);
    }

    while (!s.empty())
    { // 남아있는 막대 처리
        int h = heights[s.top()];
        s.pop();
        int w = s.empty() ? N : N - s.top() - 1;
        max_area = max(max_area, h * w);
    }

    cout << max_area << '\n';
    return 0;
}