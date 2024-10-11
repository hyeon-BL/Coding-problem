#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, K;
    int num = 1;

    cin >> N >> K;

    for (int i = 0; i < K; i++) {
        num *= N-i;
    }
    for (int i = 1; i <= K; i++) {
        num /= i;
    }
    cout << num;
}