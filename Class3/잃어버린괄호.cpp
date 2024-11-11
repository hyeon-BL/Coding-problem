#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    int cnt = 0;
    string arr[51] = {"",};
    for (int i = 0; i < s.size(); i++) {
        if(s[i] != '+' && s[i] != '-') {
            arr[cnt] += s[i];
        }
        else {
            ++cnt;
            arr[cnt] = s[i];
            ++cnt;
        }
    }

    int result = stoi(arr[0]);
    bool minus = false;
    for (int i = 1; i <= cnt; i++) {
        if (arr[i] == "-") {
            minus = true;
        } else if (arr[i] != "+") { // plus는 무시(-가 나오면 무조건 빼기 가능)
            if (minus) {
                result -= stoi(arr[i]);
            } else {
                result += stoi(arr[i]);
            }
        }
    }

    cout << result;
}