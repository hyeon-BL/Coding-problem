#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    cin >> N >> K;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--) { // O(N) (가장 큰 동전부터)
        if (K >= arr[i]) {
            count += K / arr[i];
            K %= arr[i];
        }
    }
    cout << count;
}