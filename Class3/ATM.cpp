#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + N);
    int sum = 0, temp = 0;
    for (int i = 0; i < N; i++) {
        temp += arr[i];
        sum += temp;
    }
    cout << sum;

}