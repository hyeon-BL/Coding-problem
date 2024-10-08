#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T, k, n;

    cin >> T;
    int arr[15][15] = { 0, };
    for (int i = 0; i < 15; i++) {
        arr[0][i] = i + 1;
    }
    for (int i = 1; i < 15; i++) {
        for (int j = 0; j < 15; j++) {
            for (int k = 0; k <= j; k++) {
                arr[i][j] += arr[i - 1][k];
            }
        }
    }
    for (int i = 0; i < T; i++) {
        cin >> k >> n;
        cout << arr[k][n - 1] << endl;
    }
}

/*
1 5 15 35 70 126 210 330 495 715
1 4 10 20 35 56 84 120 165 220
1 3 6 10 15 21 28 36 45 55
1 2 3 4 5 6 7 8 9 10
*/