#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
greedy algorithm
1. 크레인과 박스의 최대 하중을 내림차순으로 정렬
2. 크레인과 박스의 인덱스를 초기화
3. 크레인과 박스의 인덱스를 비교하여 크레인이 박스를 옮길 수 있는 경우 박스를 옮김
*/

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 크레인의 개수
    cin >> N;
    vector<int> cranes(N); // 크레인들의 최대 하중을 저장할 벡터
    for (int i = 0; i < N; ++i)
    {
        cin >> cranes[i]; // 크레인의 최대 하중 입력
    }
    int M; // 박스의 개수
    cin >> M;
    vector<int> boxes(M); // 박스들의 무게를 저장할 벡터
    for (int i = 0; i < M; ++i)
    {
        cin >> boxes[i]; // 박스의 무게 입력
    }

    sort(cranes.begin(), cranes.end(), greater<int>()); // 크레인들의 최대 하중을 내림차순으로 정렬
    sort(boxes.begin(), boxes.end(), greater<int>());   // 박스들의 무게를 내림차순으로 정렬

    if (boxes[0] > cranes[0])
    { // 가장 무거운 박스를 가장 강한 크레인도 옮길 수 없는 경우
        cout << -1;
        return 0;
    }

    int time = 0; // 작업 시간

    while (!boxes.empty())
    {                     // 모든 박스가 처리될 때까지 반복
        int boxIndex = 0; // 박스의 인덱스
        for (int i = 0; i < N; ++i)
        { // 각 크레인에 대해
            while (boxIndex < boxes.size() && cranes[i] < boxes[boxIndex])
            { // 크레인이 옮길 수 없는 박스를 건너뜀
                boxIndex++;
            }
            if (boxIndex < boxes.size())
            {                                          // 크레인이 옮길 수 있는 박스가 있는 경우
                boxes.erase(boxes.begin() + boxIndex); // 박스를 처리
            }
        }
        time++; // 작업 시간 증가
    }

    cout << time;
}