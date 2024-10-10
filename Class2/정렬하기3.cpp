#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, num;
    cin >> N; // N개의 수 입력(1 <= N <= 10,000,000)
    int arr[10001] = {0, };
    for (int i = 0; i < N; i++) {
        cin >> num;
        arr[num]++;
    }
    for (int i = 1; i < 10001; i++) {
        if (arr[i] == 0) continue;
        for (int j = 0; j < arr[i]; j++) {
            cout << i << endl;
        }
    }
}