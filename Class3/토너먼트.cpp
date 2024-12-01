#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K, I;
    cin >> N >> K >> I;

    int cnt = 0;
    while (K != I) { // K와 I가 같아질 때까지 반복
        K = (K + 1) / 2;
        I = (I + 1) / 2;
        cnt++;
    }
    cout << cnt; // 항상 이기면 대결하지 않는 경우는 없음
}