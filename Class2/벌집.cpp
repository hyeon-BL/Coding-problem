#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, m1;
    int count = 1;

    cin >> N;

    // 1 : 1 -> 1개
    // 2~7 : 2 -> 6개
    // 8~19 : 3 -> 12개
    // 20~37 : 4 -> 18개
    // 38~61 : 5 -> 24개

    m1 = N - 1;
    if (m1 <= 0) {
        cout << 1;
        return 0;
    }
    for (int i=1; i<N; i++) {
        m1 -= 6 * i;
        if (m1 <= 0) {
            cout << i + 1;
            return 0;
        }
    }
}