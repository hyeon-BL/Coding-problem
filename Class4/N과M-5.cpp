#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 백트래킹
void dfs(int depth, int N, int M, vector<int> &sequence, vector<int> &input, vector<bool> &used)
{
    if (depth == M)
    {
        for (int num : sequence) // 수열 출력
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 0; i < N; i++)
    {
        if (!used[i]) // 사용하지 않은 수라면
        {
            used[i] = true;
            sequence.push_back(input[i]);
            dfs(depth + 1, N, M, sequence, input, used); // 나머지 수
            sequence.pop_back();
            used[i] = false; // 다시 사용하지 않은 상태로 변경
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> sequence;
    vector<int> input(N);
    vector<bool> used(N, false);
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    sort(input.begin(), input.end());
    dfs(0, N, M, sequence, input, used);

    return 0;
}