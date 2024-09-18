#include<iostream>
using namespace std;

int main() {
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        cout << string(N-i, ' ') << string(i, '*') << '\n'; // string(n, c) returns a string with n characters of c
    }
}