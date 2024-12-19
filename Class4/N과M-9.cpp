#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int depth, int N, int M, vector<int> &sequence, vector<int> &input, vector<bool> &used)
{
    if (depth == M)
    {
        for (int num : sequence)
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    int lastUsed = -1;
    for (int i = 0; i < N; i++)
    {
        if (!used[i] && input[i] != lastUsed)
        { // 중복 제거(중복은 항상 붙어서 나옴) -> O(1)
            used[i] = true;
            sequence.push_back(input[i]);
            dfs(depth + 1, N, M, sequence, input, used);
            sequence.pop_back();
            used[i] = false;
            lastUsed = input[i];
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