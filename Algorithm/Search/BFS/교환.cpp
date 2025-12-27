#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <string>
using namespace std;

int bfs(string num, int K)
{
    queue<string> q; // {현재 숫자}
    int max_num = -1;
    int cnt = 0;

    q.push(num);

    while (!q.empty() && cnt < K)
    {
        unordered_set<string> visited; // 방문한 숫자 저장 (매 count마다 초기화)
        int size = q.size();           // 현재 큐의 크기 (사전 저장 -> 동적 할당 방지)

        for (int s = 0; s < size; s++)
        {                               // 현재 단계의 모든 숫자에 대해
            string current = q.front(); // 현재 숫자
            q.pop();

            // 모든 조합을 만들어서 큐에 추가
            for (int i = 0; i < current.size() - 1; i++)
            {
                for (int j = i + 1; j < current.size(); j++)
                {
                    swap(current[i], current[j]);

                    // 숫자가 0으로 시작하지 않고 방문하지 않은 경우
                    if (current[0] != '0' && visited.find(current) == visited.end())
                    {
                        q.push(current); // 큐에 추가
                        visited.insert(current);

                        if (cnt == K - 1) // 마지막 연산인 경우
                        {
                            max_num = max(max_num, stoi(current)); // 최대값 갱신
                        }
                    }
                    swap(current[i], current[j]); // 원래 상태로 되돌림
                }
            }
        }
        // 연산 횟수 증가
        cnt++;
    }

    return max_num; // 최대값 반환
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string num; // 연산할 숫자
    int K;      // 연산 횟수
    cin >> num >> K;

    int result = bfs(num, K); // BFS 탐색
    cout << result << '\n';   // 결과 출력
}