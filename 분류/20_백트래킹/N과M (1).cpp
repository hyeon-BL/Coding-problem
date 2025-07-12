#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 백트래킹
void dfs(int start, int depth, int N, int M, vector<int> &sequence, set<int> &used)
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

    for (int i = 1; i <= N; i++)
    {
        if (used.count(i) == 0) // 사용되지 않은 숫자만 선택
        {
            sequence.push_back(i);
            used.insert(i); // 선택한 숫자를 사용된 집합에 추가
            dfs(i + 1, depth + 1, N, M, sequence, used);
            sequence.pop_back(); // 바로 이전에 넣은 원소를 제거
            used.erase(i);       // 다시 사용 가능
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<int> sequence;            // 수열을 저장할 벡터
    set<int> used;                   // 사용된 숫자를 저장할 집합 (중복 방지)
    dfs(1, 0, N, M, sequence, used); // 1부터 시작
    return 0;
}