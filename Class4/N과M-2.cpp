#include <iostream>
#include <vector>
using namespace std;

// 백트래킹
void dfs(int start, int depth, int N, int M, vector<int> &sequence)
{
    if (depth == M) // M개를 모두 뽑았을 때
    {
        for (int num : sequence) // 수열 출력
        {
            cout << num << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= N; i++)
    {
        sequence.push_back(i);
        dfs(i + 1, depth + 1, N, M, sequence);
        sequence.pop_back(); // 바로 이전에 넣은 원소를 제거
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> sequence;
    dfs(1, 0, N, M, sequence);

    return 0;
}