#include<iostream>
using namespace std;

int main() {
    int X;
    cin >> X;

    string binary = "";
    int cnt = 0;
    while (X > 0) {
        binary = (X % 2 == 0 ? "0" : "1") + binary;
        X /= 2;
    }
    for (int i = 0; i < binary.size(); i++) {
        if (binary[i] == '1') cnt++;
    }
    cout << cnt;
}