#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
using namespace std;

double minLength = numeric_limits<double>::max(); // 최솟값 저장
vector<pair<int, int>> points;                    // 점들의 좌표 저장
int N;                                            // 점의 개수
int totalSumX = 0, totalSumY = 0;                 // 전체 점의 좌표 합

// 벡터의 길이를 계산하는 함수
double calculateVectorLength(double x, double y)
{
    return sqrt((x * x) + (y * y));
}

// 백트래킹을 이용해 벡터 매칭에 있는 벡터의 합의 길이의 최솟값을 찾는 함수
void backtrack(int idx, int selected, double sumX, double sumY)
{ // idx: 현재 점의 인덱스, selected: 선택한 점의 개수, sumX: x좌표의 합, sumY: y좌표의 합
    // static vector<bool> visited(20, false); // 방문 여부를 저장하는 벡터(디버깅용)

    // N개의 점 중 절반을 선택했을 때(벡터 매칭)
    if (selected == N / 2)
    {
        // 벡터의 길이를 계산
        int outX = totalSumX - sumX; // 선택하지 않은 점의 x좌표의 합
        int outY = totalSumY - sumY; // 선택하지 않은 점의 y좌표의 합
        double length = calculateVectorLength(sumX - outX, sumY - outY);
        minLength = min(minLength, length);
        // for (int i = 0; i < N; i++)
        // {
        //     if (visited[i])
        //         cout << 1 << " ";
        //     else
        //         cout << 0 << " ";
        // }
        // cout << " : " << sumX << " " << sumY << " " << outX << " " << outY << " : " << length << '\n';
        return;
    }

    // 더 이상 선택할 점이 없을 때
    if (idx == N)
        return;

    // 현재 점을 선택하는 경우
    // visited[idx] = true; // 현재 점을 선택했음을 표시
    backtrack(idx + 1, selected + 1, sumX + points[idx].first, sumY + points[idx].second);
    // visited[idx] = false; // 현재 점을 선택 해제

    // 현재 점을 선택하지 않는 경우
    backtrack(idx + 1, selected, sumX, sumY);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T; // 테스트 케이스 수
    cin >> T;

    while (T--)
    {
        totalSumX = 0;
        totalSumY = 0;

        cin >> N; // 점의 개수 (짝수)
        points.resize(N);

        for (int i = 0; i < N; i++)
        {
            cin >> points[i].first >> points[i].second; // 점의 좌표 입력
            totalSumX += points[i].first;               // x좌표의 합
            totalSumY += points[i].second;              // y좌표의 합
        }

        minLength = numeric_limits<double>::max(); // 최솟값 초기화
        backtrack(0, 0, 0, 0);                     // 백트래킹 시작

        cout.precision(12);
        cout << fixed << minLength << '\n'; // 결과 출력
    }

    return 0;
}