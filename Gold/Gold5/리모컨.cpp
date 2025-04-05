#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 이동하려는 채널
    cin >> N;

    int M; // 고장난 버튼의 개수
    cin >> M;
    vector<int> broken(10, 0); // 고장난 버튼을 저장할 벡터
    for (int i = 0; i < M; ++i)
    {
        int b;
        cin >> b;      // 고장난 버튼 입력
        broken[b] = 1; // 고장난 버튼 표시
    }

    int ans = abs(N - 100); // 초기값: 현재 채널(100)에서 이동하려는 채널(N)까지의 거리
    for (int i = 0; i <= 999999; ++i)
    {                            // 모든 채널을 확인
        string s = to_string(i); // 채널 번호를 문자열로 변환
        bool isBroken = false;   // 고장난 버튼 여부
        for (char c : s)
        {
            if (broken[c - '0'])
            { // 고장난 버튼이 있는 경우
                isBroken = true;
                break;
            }
        }
        if (!isBroken)
        {                                               // 고장난 버튼이 없는 경우
            ans = min(ans, abs(N - i) + (int)s.size()); // 최소값 갱신
            // abs(N - i): 이동하려는 채널(N)과 현재 채널(i) 간의 거리
            // (int)s.size(): 채널 번호를 입력하는 데 필요한 버튼 개수
        }
    }

    cout << ans; // 결과 출력
    return 0;
}