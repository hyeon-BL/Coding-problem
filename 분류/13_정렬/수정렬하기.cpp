#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 수의 개수
    cin >> N;
    vector<int> arr(N); // arr: 수를 저장할 벡터
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i]; // 수 입력
    }

    // 버블 정렬
    // O(N^2) 시간 복잡도
    for (int i = 0; i < N - 1; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]); // 오름차순 정렬
            }
        }
    }
    // 정렬된 수 출력
    for (int i = 0; i < N; i++)
    {
        cout << arr[i] << '\n';
    }
}