#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int X;
    cin >> X;

    int numerator = 1, denominator = 1;
    int sum = 2; // sum of numerator and denominator
    int count = 1; // current position in the sequence

    while (count < X) {
        if (sum % 2 == 0) { // even sum, move down-left
            if (numerator == 1) {
                denominator++; // move down
                sum++;
            } else {
                denominator++; // move down
                numerator--; // move left
            }
        } else { // odd sum, move up-right
            if (denominator == 1) {
                numerator++; // move right
                sum++;
            } else {
                denominator--; // move up
                numerator++; // move right
            }
        }
        count++;
    }

    cout << numerator << '/' << denominator;
}