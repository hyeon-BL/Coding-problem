#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, num;
    int arr[100000];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num;
        arr[i] = num;
    }
    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << '\n';
    }
}