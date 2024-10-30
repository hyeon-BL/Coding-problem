#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int* count = new int[N + 1];
    count[1] = 0;

    for (int i = 2; i <= N; i++) {
        count[i] = count[i - 1] + 1; // 1을 빼는 경우
        if (i % 2 == 0) count[i] = min(count[i], count[i / 2] + 1); // 2로 나누어 떨어지는 경우
        if (i % 3 == 0) count[i] = min(count[i], count[i / 3] + 1); // 3으로 나누어 떨어지는 경우
    }
    cout << count[N];
}