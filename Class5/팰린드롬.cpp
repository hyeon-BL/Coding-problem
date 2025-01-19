#include <iostream>
#include <vector>
using namespace std;

// 팰린드롬 : 앞에서 읽으나 뒤에서 읽으나 같은 문자열
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, S, E;
    cin >> N;
    vector<int> arr(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    cin >> M;
    vector<vector<int>> dp(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    { // 길이가 1인 문자열은 무조건 팰린드롬
        dp[i][i] = 1;
    }
    for (int i = 0; i < N - 1; i++)
    { // 길이가 2인 문자열은 두 문자가 같으면 팰린드롬
        if (arr[i] == arr[i + 1])
        {
            dp[i][i + 1] = 1;
        }
    }
    for (int i = 2; i < N; i++)
    { // i는 팰린드롬의 길이 - 1
        for (int j = 0; j < N - i; j++)
        { // j는 시작점
            if (arr[j] == arr[j + i] && dp[j + 1][j + i - 1])
            { // 시작점과 끝점이 같고 그 사이의 문자열이 팰린드롬이면 팰린드롬
                dp[j][j + i] = 1;
            }
        }
    }

    for (int i = 0; i < M; i++)
    { // S-1부터 E-1까지 팰린드롬인지 확인
        cin >> S >> E;
        cout << dp[S - 1][E - 1] << '\n'; // 1이면 팰린드롬, 0이면 팰린드롬이 아님
    }
}