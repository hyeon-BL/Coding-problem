#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    int size[6];
    int T, P;
    int set = 0;


    cin >> N;
    cin >> size[0] >> size[1] >> size[2] >> size[3] >> size[4] >> size[5];
    cin >> T >> P;

    for (int i = 0; i < 6; i++) {
        int n;
        if (size[i] % T == 0) {
            n = size[i] / T;
        } else {
            n = size[i] / T + 1;
        }
        set += n;
    }
    cout << set << endl;
    cout << N / P << ' ' << N % P;
}