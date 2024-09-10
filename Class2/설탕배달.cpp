#include<iostream>
using namespace std;

int main() {
    int N, r3, r5;
    int o5 = 0, o3 = 0;
    cin >> N;

    for (int i = 0; i <= (N/5); i++) {
        r5 = N  - (5 * i);
        for (int j = 0; j <= (r5/3); j++) {
            r3 = r5 - (3 * j);
            if (r3 == 0) {
                o3 = j;
                o5 = i;
            }
            else {
                continue;
            }
        }
    }
    if (o5 == 0 && o3 == 0) {
        cout << -1;
        return 0;
    }
    cout << o5 + o3;
}