#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N1, N2;
    int iN1, iN2;
    int temp = 1;

    cin >> N1 >> N2;
    iN1 = N1;
    iN2 = N2;

    while (temp != 0) {
        temp = N1 % N2;
        N1 = N2;
        N2 = temp;
    }
    cout << N1 << '\n';
    cout << iN1 * iN2 / N1;
}