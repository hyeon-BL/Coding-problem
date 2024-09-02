#include <iostream>
using namespace std;
int main() {
    int N, two = 0, five = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        int temp = i;
        while (temp % 2 == 0) {
            two++;
            temp /= 2;
        }
        while (temp % 5 == 0) {
            five++;
            temp /= 5;
        }
    }
    cout << (two < five ? two : five);
}