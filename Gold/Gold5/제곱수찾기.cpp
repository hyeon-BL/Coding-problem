#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;
    vector<vector<int>> arr(N + 1, vector<int>(M + 1, 0));

    for (int i = 1; i <= N; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
        {
            arr[i][j] = s[j - 1] - '0'; // 문자열을 정수로 변환하여 배열에 저장
        }
    }

    int maxSquare = -1;

    for (int startRow = 1; startRow <= N; startRow++)
    { // 모든 시작 row
        for (int startCol = 1; startCol <= M; startCol++)
        { // 모든 시작 col
            for (int rowStep = -N; rowStep <= N; rowStep++)
            { // 모든 row 이동 step (-1, 0, 1)
                for (int colStep = -M; colStep <= M; colStep++)
                { // 모든 col 이동 step (-1, 0, 1)
                    if (rowStep == 0 && colStep == 0)
                        continue;

                    int currentRow = startRow;
                    int currentCol = startCol;
                    string numberStr = "";

                    // 이동하면서 숫자 문자열 생성
                    while (currentRow >= 1 && currentRow <= N && currentCol >= 1 && currentCol <= M)
                    {
                        numberStr += to_string(arr[currentRow][currentCol]);
                        int number = stoi(numberStr);

                        // 제곱수인지 확인
                        int sqrtNum = sqrt(number);
                        if (sqrtNum * sqrtNum == number)
                        {
                            maxSquare = max(maxSquare, number);
                        }

                        currentRow += rowStep;
                        currentCol += colStep;
                    }
                }
            }
        }
    }

    cout << maxSquare;
    return 0;
}