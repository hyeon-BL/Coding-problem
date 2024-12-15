#include<iostream>
#include <vector>
using namespace std;    

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return a * b / gcd(a, b);
}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;

    int N, M, x, y;
    for (int i = 0; i < T; i++) {
        cin >> N >> M >> x >> y;

        int result = -1;

        int max = lcm(N, M); // 가능한 최대값
        for (int j = x; j <= max; j += N) { // O(N)
            int temp = j % M;
            if (temp == 0) temp = M; // M으로 나누어 떨어지는 경우(같은 경우)
            if (temp == y) { // 나머지가 y와 같은 경우(정답답)
                result = j;
                break;
            }
        }
        cout << result << "\n";
    }
}