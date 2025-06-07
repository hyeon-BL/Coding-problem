#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int arr[1001];
    int N, k;
    cin >> N >> k; // N: 배열 크기, k: k번째 수
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i]; // 배열 입력
    }

    sort(arr, arr + N, greater<int>()); // 내림차순 정렬
    cout << arr[k - 1] << '\n';
}