#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M, cnt1, cnt2;
    int result = 64;

    cin >> N >> M;
    char** arr = new char*[N+1];
    for (int i = 0; i < N; i++) {
        arr[i] = new char[M+1];
        for (int j = 0; j < M; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N-7; i++) { // 8x8 체스판을 만들 수 있는 모든 경우의 수
        for (int j = 0; j < M-7; j++) {
            cnt1 = 0;
            cnt2 = 0;

            for (int k = i; k < i + 8; k++) { // 8x8 체스판을 만들어서 검사
                for (int l = j; l < j + 8; l++) {
                    if ((k + l) % 2 == 0) {  // 행과 열의 합이 짝수인 경우(주변이 같은 색)
                        if (arr[k][l] != 'B') { // ': 단일 문자를 표현할 때 사용, " : 문자열을 표현할 때 사용
                            cnt1++;
                        }
                        if (arr[k][l] != 'W') {
                            cnt2++;
                        }
                    }
                    else {
                        if (arr[k][l] != 'W') {
                            cnt1++;
                        }
                        if (arr[k][l] != 'B') {
                            cnt2++;
                        }
                    }
                }
            }
            result = min(result, min(cnt1, cnt2)); // 두 경우 중 작은 값을 result에 저장
        }
    }
    cout << result;
}