#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cnt = 0;
    string N, s;
    cin >> N;
    s = N;

    if (N.size() == 1) {
        N = "0" + N;
    }
    while (1) {
        int a = N[0] - '0'; // char to int ('0' == 48)
        int b = N[1] - '0'; // char to int
        int c = a + b;
        if (c >= 10) {
            c = c % 10;
        }
        N = to_string(b) + to_string(c);
        cnt++;
        if (N == s || N == "0" + s) {
            break;
        }
    }
    cout << cnt;

}