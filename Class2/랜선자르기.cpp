#include <iostream>
#include <algorithm>
using namespace std;

long K, N; // K: 랜선의 개수, N: 필요한 랜선의 개수
long arr[10000];
int res;

void binary(long long low, long long high) { // long long으로 선언(overflow 방지)
    if (low > high) {
        return;
    }
    long long mid = (low + high) / 2;
    long cnt = 0;
    for (int i = 0; i < K; i++) {
        if (arr[i] == 0) {
            break; // 요소가 0이면 반복을 멈춤
        }
        cnt += arr[i] / mid; // 만들어지는 랜선의 개수
    }
    if (cnt >= N) {
        res = mid;
        binary(mid + 1, high);
    }
    else {
        binary(low, mid - 1);
    }   
}

int main() {
    int length; // 랜선의 길이
    long long low = 1, high = 0; // 이진 탐색을 위한 변수
    cin >> K >> N;
    for (int i = 0; i < K; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + K);
    high = arr[K - 1];
    binary(low, high + 1);
    cout << res;
    return 0;
}