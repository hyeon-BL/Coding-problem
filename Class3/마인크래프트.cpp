#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, B;
    cin >> N >> M >> B;

    int** arr = new int*[N];
    for (int i = 0; i < N; ++i) {
        arr[i] = new int[M];
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        sort(arr[i], arr[i] + M);
    }


    for (int i = 0; i < N; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}