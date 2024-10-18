#include<iostream>
#include<algorithm>
using namespace std;

int isExist(int* arr, int N, int target) { // 이진 탐색 O(N)
    int start = 0;
    int end = N - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == target) {
            return 1;
        }
        else if (arr[mid] < target) {
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }
    return 0;
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;

    cin >> N;
    int* arr1 = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr1[i];
    }
    sort(arr1, arr1 + N); // 이진 탐색을 위한 정렬 O(NlogN)

    cin >> M;
    int* arr2 = new int[M];
    for (int i = 0; i < M; i++) {
        cin >> arr2[i];
    }
    for (int i = 0; i < M; i++) {
        cout << isExist(arr1, N, arr2[i]) << '\n';
    }
}