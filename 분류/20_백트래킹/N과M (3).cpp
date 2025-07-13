#include <iostream>
#include <vector>
using namespace std;

vector<int> sequence;

void dfs(int depth, int N, int M)
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
    for (int i = 1; i <= N; i++)
    {
        sequence.push_back(i);
        dfs(depth + 1, N, M);
        sequence.pop_back();
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    dfs(0, N, M);
}