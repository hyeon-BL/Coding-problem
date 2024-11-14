#include<iostream>
using namespace std;

long long getWood(int* arr, int N, int height) { // height보다 높은 나무들의 합
    long long total = 0;
    for (int i = 1; i <= N; i++) {
        if (arr[i] > height) {
            total += arr[i] - height;
        }
    }
    return total;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    long long N, M;
    cin >> N >> M;
    
    int* arr = new int[N + 1];
    int max = 0;

    for (int i = 1; i <= N; i++) {
        cin >> arr[i];
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    long long left = 0, right = max, mid;
    while (left <= right) {
        mid = (left + right) / 2;
        if (getWood(arr, N, mid) >= M) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << '\n';

    delete[] arr;
    return 0;
}