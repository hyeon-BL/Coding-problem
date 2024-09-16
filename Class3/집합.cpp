#include<iostream>
using namespace std;

int main() {
    cin.tie(0); // cin과 cout의 묶음을 풀어줌 -> cin만
	ios::sync_with_stdio(0); // 시간 초과 방지 -> C와 C++의 버퍼를 분리
    int M; // 집합의 개수
    string input;
    string S[21] = {}; // 집합 S
    for (int i = 1; i <= 20; i++) {
        S[i] = "0";
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> input;
        if (input == "all") {
            for (int j = 1; j <= 20; j++) {
                S[j] = "1";
            }
        }
        else if (input == "empty") {
            for (int j = 1; j <= 20; j++) {
                S[j] = "0";
            }
        }
        else {
            int x;
            cin >> x;
            if (input == "add") {
                S[x] = "1";
            }
            else if (input == "remove") {
                S[x] = "0";
            }
            else if (input == "check") {
                if (i != M - 1) {
                    cout << S[x] << '\n';
                }
                else {
                cout << S[x];
                }   
            }
            else if (input == "toggle") {
                if (S[x] == "1") {
                    S[x] = "0";
                }
                else {
                    S[x] = "1";
                }
            }
        }
    }
}