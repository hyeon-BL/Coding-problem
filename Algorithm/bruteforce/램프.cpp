#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> arr; // 2차원 배열
int N, M;                // N: 행, M: 열
int K;                   // K: 스위치를 누를 횟수
int max_rows = 0;        // 켜져있는 최대 행의 수

// void flip(int col) // 열을 뒤집는 함수
// {
//     for (int i = 0; i < N; i++)
//     {
//         arr[i][col] ^= 1; // XOR 연산으로 스위치 상태 변경
//     }
// }

// int countOn(int row) // 행이 켜져있는지 확인하는 함수
// {
//     for (int j = 0; j < M; j++)
//     {
//         if (arr[row][j] == 0)
//             return 0; // 꺼져있으면 0 반환
//     }
//     return 1; // 모두 켜져있으면 1 반환
// }

// void backtrack(int idx, int cnt)
// {

//     if ((K - cnt) % 2 == 0)
//     {
//         int total = 0; // 켜져있는 행의 수
//         for (int i = 0; i < N; i++)
//         {
//             total += countOn(i); // 각 행이 켜져있는지 확인
//         }
//         max_rows = max(max_rows, total); // 최대 행의 수 갱신
//     }

//     if (idx == M - 1) // 모든 열을 탐색한 경우
//     {
//         cout << max_rows << '\n'; // 결과 출력
//         exit(0);                  // 프로그램 종료
//     }

//     for (int i = idx; i < M; i++)
//     {
//         flip(i); // 열을 뒤집음
//         backtrack(i + 1, cnt + 1);
//         flip(i); // 원래 상태로 되돌림
//     }
// }

int calculateMaxRows()
{
    int result = 0; // 켜져있는 최대 행의 수

    for (int i = 0; i < N; i++)
    {
        int cnt = 0; // 현재 행에서 꺼져있는 램프의 수
        int sim = 0; // 동일한 상태를 가진 행의 수

        // 현재 행에서 꺼져있는 램프의 수 계산
        for (int j = 0; j < M; j++)
        {
            if (arr[i][j] == 0)
            {
                cnt++;
            }
        }

        // 꺼져있는 램프의 수가 K 이하이고, (K - cnt)가 짝수인 경우
        if (cnt <= K && (K - cnt) % 2 == 0)
        {
            for (int k = 0; k < N; k++)
            {
                if (arr[i] == arr[k])
                {
                    sim++;
                }
            }
            result = max(result, sim);
        }
    }

    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N >> M;
    arr.resize(N, vector<int>(M)); // 2차원 배열 크기 조정
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < M; j++)
        {
            arr[i][j] = s[j] - '0'; // 문자 -> 정수 변환
        }
    }

    cin >> K;
    int result = calculateMaxRows(); // 최대 행의 수 계산
    cout << result << '\n';          // 결과 출력
}