#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int* A = new int[N];
    int* B = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    sort(A, A + N);
    sort(B, B + N, greater<int>());
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += A[i] * B[i];
    }
    cout << result;
}