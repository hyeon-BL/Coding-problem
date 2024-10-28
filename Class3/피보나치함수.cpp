#include<iostream>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;

    cin >> T;
    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        int a = 1, b = 0;
        for (int j = 0; j < N; j++) { // dynamic programming(bottom-up)
            int temp = a;
            a = b;
            b += temp;
        }
        cout << a << ' ' << b << '\n';
    }
}