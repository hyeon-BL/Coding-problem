#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int arr[5];
    int sum = 0; // 합계 변수
    for (int i = 0; i < 5; i++)
    {
        cin >> arr[i]; // 수 입력
        sum += arr[i]; // 입력된 수의 합계 계산
    }

    // selection sort
    // O(N^2) 시간 복잡도
    for (int i = 0; i < 4; i++)
    {
        int minIdx = i; // 현재 위치를 최소값으로 가정
        for (int j = i + 1; j < 5; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j; // 더 작은 값이 있으면 최소값 인덱스 갱신
            }
        }
        if (minIdx != i)
        {
            swap(arr[i], arr[minIdx]); // 최소값과 현재 위치의 값 교환
        }
    }

    cout << sum / 5 << '\n'; // 평균 출력
    cout << arr[2] << '\n';  // 중앙값 출력 (정렬된 배열의 중간 값)
}