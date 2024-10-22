#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    vector<int> arr(N);
    for (int i = 0; i < N; i++) {
        arr[i] = i + 1; // 1부터 N까지의 수로 초기화
    }

    int idx = 0;
    cout << "<";
    while (arr.size() > 1) {
        idx = (idx + K - 1) % arr.size(); // 인덱스 계산(size로 나눠야 순환 가능)
        cout << arr[idx] << ", ";
        arr.erase(arr.begin() + idx); // 요소 제거
    }
    cout << arr[0] << ">\n"; // 마지막 요소 출력

    return 0;
}