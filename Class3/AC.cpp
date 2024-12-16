#include<iostream>
#include<deque>
#include<sstream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T, n;
    string P, str;
    
    cin >> T;
    while(T--) {
        cin >> P;
        cin >> n;
        cin >> str;

        deque<int> dq;
        string num;
        for (char c : str) {
            if (isdigit(c)) {
                num += c;
            } else if (c == ',' || c == ']') {
                if (!num.empty()) {
                    dq.push_back(stoi(num));
                    num.clear();
                }
            }
        }

        bool reverseFlag = false;
        for (char c : P) { // O(P.size())
            if (c == 'R') {
                reverseFlag = !reverseFlag; // 뒤집기 -> O(1)
            } else if (c == 'D') {
                if (dq.empty()) {
                    cout << "error\n";
                    goto end;
                }
                if (reverseFlag) {
                    dq.pop_back(); // 뒤에서 제거
                } else {
                    dq.pop_front(); // 앞에서 제거
                }
            }
        }

        cout << '[';
        if (reverseFlag) {
            for (auto it = dq.rbegin(); it != dq.rend(); ++it) {
                cout << *it; // 역방향 출력
                if (it + 1 != dq.rend()) cout << ',';
            }
        } else {
            for (auto it = dq.begin(); it != dq.end(); ++it) {
                cout << *it; // 정방향 출력
                if (it + 1 != dq.end()) cout << ',';
            }
        }
        cout << "]\n";
        end:;
    }
    return 0;
}