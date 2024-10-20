#include <iostream>
#include <algorithm>
using namespace std;

int countOccurrences(int* arr, int size, int target) {
    // lower_bound와 upper_bound를 사용하여 target의 범위를 찾음
    auto lower = lower_bound(arr, arr + size, target); // target 이상의 첫 번째 원소
    auto upper = upper_bound(arr, arr + size, target); // target 초과의 첫 번째 원소
    return upper - lower; // target의 개수 반환
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N;

    int* have = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> have[i];
    }
    sort(have, have + N); // O(NlogN)

    cin >> M;
    int* check = new int[M];
    for (int i = 0; i < M; i++) {
        cin >> check[i];
    }

    // 각 check 요소에 대해 have 배열에서의 개수를 출력
    for (int i = 0; i < M; i++) {
        cout << countOccurrences(have, N, check[i]) << ' ';
    }
    cout << '\n';

    delete[] have;
    delete[] check;

    return 0;
}