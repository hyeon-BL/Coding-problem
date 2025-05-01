#include <iostream>
#include <stack>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    stack<pair<int, int>> line; // 스택 구조체 (height, count)
    long long cnt = 0;          // 사람이 볼 수 있는 사람의 수

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        int sameHeightCount = 1;

        // num보다 작은 사람들을 스택에서 pop
        while (!line.empty() && line.top().first < num)
        {
            cnt += line.top().second; // pop한 사람의 수를 cnt에 더함
            line.pop();
        }

        // num과 같은 높이의 사람들은 sameHeightCount에 저장 후 pop
        if (!line.empty() && line.top().first == num)
        {
            sameHeightCount = line.top().second + 1;
            cnt += line.top().second; // 같은 높이의 사람도 볼 수 있음
            line.pop();
        }

        // 마지막으로 num보다 큰 사람을 만났을 때, cnt에 1을 더함(이후는 볼 수 없음)
        if (!line.empty())
        {
            cnt++;
        }

        // 스택에 num을 push
        line.push({num, sameHeightCount});
    }

    cout << cnt;
}