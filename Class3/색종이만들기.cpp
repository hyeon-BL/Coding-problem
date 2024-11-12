#include<iostream>
using namespace std;

int N;
int arr[128][128]; // 2^7 = 128
int blue = 0, white = 0;

void countSquares(int x, int y, int size) {
    int color = arr[x][y];
    bool sameColor = true;
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != color) {
                sameColor = false;
                break;
            }
        }
        if (!sameColor) break;
    }

    if (sameColor) {
        if (color == 1) blue++;
        else white++;
    } else {
        int newSize = size / 2;
        countSquares(x, y, newSize); // 왼쪽 위
        countSquares(x, y + newSize, newSize); // 오른쪽 위
        countSquares(x + newSize, y, newSize); // 왼쪽 아래
        countSquares(x + newSize, y + newSize, newSize); // 오른쪽 아래
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    countSquares(0, 0, N);

    cout << white << '\n' << blue;
    return 0;
}