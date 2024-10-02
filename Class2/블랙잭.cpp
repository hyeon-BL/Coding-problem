#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M, sum = 0;
    cin >> N >> M;

    int* arr = new int[N];

    for (int i=0; i<N; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            for (int k=0; k<N; k++) {
                if (i != j && j != k && k != i) {
                    if (arr[i] + arr[j] + arr[k] <= M) {
                        sum = max(sum, arr[i] + arr[j] + arr[k]);
                    }
                }
            }
        }
    }
    cout << sum;
}