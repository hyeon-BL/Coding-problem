#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    double temp, sum = 0;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    M = arr[N - 1];

    for (int i = 0; i < N; i++) {
        temp = (static_cast<double>(arr[i]) / M) * 100; // 실수형 나눗셈
        sum += temp;
    }
    cout << sum / (double)N;



}