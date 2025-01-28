#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M; // N * M 크기의 직사각형
    cin >> N >> M;
    vector<vector<int>> rectangle(N, vector<int>(M));
    for (int i = 0; i < N; i++)
    {
        string row;
        cin >> row;
        for (int j = 0; j < M; j++)
        {
            rectangle[i][j] = row[j] - '0';
        }
    }

    // max_size: (i, j)에서 만들 수 있는 가장 큰 정사각형의 한 변의 길이
    int max_size = 1;
    for (int size = 1; size < min(N, M); size++)
    { // size: 정사각형의 한 변의 길이
        for (int i = 0; i < N - size; i++)
        { // i: 행
            for (int j = 0; j < M - size; j++)
            { // j: 열
                if (rectangle[i][j] == rectangle[i + size][j] && rectangle[i][j] == rectangle[i][j + size] && rectangle[i][j] == rectangle[i + size][j + size])
                { // (i, j)에서 size 크기의 정사각형이 만들어지는지 확인
                    max_size = max(max_size, size + 1);
                }
            }
        }
    }

    cout << max_size * max_size;
}