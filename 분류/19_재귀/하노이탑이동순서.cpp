#include <iostream>
#include <vector>
using namespace std;

int N; // 전역 변수로 N을 선언

int hanoi(int n, int from, int to, int aux)
{                                        // n: 옮길 원판의 개수, from: 시작 기둥, to: 목표 기둥, aux: 보조 기둥
    static vector<pair<int, int>> moves; // 이동 경로를 저장할 벡터
    if (n == 1)
    {
        moves.push_back({from, to});
        return 1;
    }

    int count = 0;
    count += hanoi(n - 1, from, aux, to); // 1을 제외한 n-1개의 원판을 from에서 aux로 옮김
    moves.push_back({from, to});          // 가장 큰 원판을 from에서 to로 옮김
    count += 1;                           // 가장 큰 원판을 옮긴 횟수 추가
    count += hanoi(n - 1, aux, to, from); // n-1개의 원판을 aux에서 to로 옮김

    if (n == N)
    {
        cout << count << '\n'; // 각 단계에서 옮긴 횟수를 출력
        for (const auto &move : moves)
        {
            cout << move.first << ' ' << move.second << '\n'; // 옮긴 경로 출력
        }
    }
    return count; // 총 옮긴 횟수 반환
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;

    hanoi(N, 1, 3, 2); // 1번 기둥에서 3번 기둥으로 옮김, 2번 기둥은 보조 기둥

    if (N == 1)
    {
        cout << "1\n1 3\n";
    }
    return 0;
}