#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;

    cin >> N >> M;
    char** arr = new char*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[M];
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }
    int xcount = 0, dcount = 0;
    for (int i = 0; i < N; i++) { // Check if there is 'X' in each row
        bool hasX = false;
        for (int j = 0; j < M; j++) {
            if (arr[i][j] == 'X') {
                hasX = true;
                break;
            }
        }
        if (!hasX) {
            xcount++;
        }
    }

    for (int j = 0; j < M; j++) { // Check if there is 'X' in each column
        bool hasX = false;
        for (int i = 0; i < N; i++) {
            if (arr[i][j] == 'X') {
                hasX = true;
                break;
            }
        }
        if (!hasX) {
            dcount++;
        }
    }

    cout << max(xcount, dcount); // Output the maximum number of rows or columns that do not have 'X'

    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}