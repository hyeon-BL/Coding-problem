#include<iostream>
using namespace std;

int main() {
    int N, sum = 0;
    cin >> N;
    string s;
    cin >> s;
    for (int i = 0; i < N; i++) {
        sum += (int)s[i] - 48; // ASCII code of '0' is 48
    }
    cout << sum;
}