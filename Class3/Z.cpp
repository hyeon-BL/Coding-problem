#include<iostream>
using namespace std;


// divide and conquer(top-down) 방식으로 풀이
int Z(int n, int r, int c) {
    if (n == 0) return 0;
    int half = 1 << (n - 1); // 2^(n-1)
    if (r < half && c < half) return Z(n - 1, r, c); // 1번째 사각형
    if (r < half && c >= half) return half * half + Z(n - 1, r, c - half); // 2번째 사각형
    if (r >= half && c < half) return 2 * half * half + Z(n - 1, r - half, c); // 3번째 사각형
    return 3 * half * half + Z(n - 1, r - half, c - half); // 4번째 사각형
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, r, c;
    cin >> N >> r >> c;

    cout << Z(N, r, c);
    return 0;
}