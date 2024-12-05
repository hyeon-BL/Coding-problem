#include<iostream>
using namespace std;

int GCD(int a, int b) {
    int c;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int LCM(int a, int b) {
    return (a * b) / GCD(a, b);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int arr[5];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];

    int min_lcm = INT_MAX;

    for (int i = 0; i < 5; i++) {
        for (int j = i + 1; j < 5; j++) {
            for (int k = j + 1; k < 5; k++) {
                int lcm = LCM(arr[i], LCM(arr[j], arr[k]));
                min_lcm = min(min_lcm, lcm);
            }
        }
    }

    cout << min_lcm << endl;
    return 0;
}