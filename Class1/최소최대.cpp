#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, min, max;

    cin >> N;
    int* arr = new int[N];
    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<N; i++) {
        if (i == 0) {
            min = arr[i];
            max = arr[i];
        }
        else {
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }
    cout << min << ' ' << max;

}