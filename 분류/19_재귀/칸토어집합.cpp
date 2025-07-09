#include<iostream>
#include<cmath>
using namespace std;

void cantor(int n, int s) {
    if (n == 1) {
        cout << "-";
        return;
    };
    int m = n / 3;
    cantor(m, 0);
    for (int i = 0; i < m; i++) {
        cout << " ";
    }
    cantor(m, 2*m+1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(true) {
        int n;
        cin >> n;
        if (cin.eof()) break; // End of input check
        
        cantor(pow(3, n), 0);
        cout << "\n";
    }
}