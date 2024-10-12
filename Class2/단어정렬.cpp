#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    string* arr = new string[N];

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - 1; j++) {
            if (arr[j].length() > arr[j+1].length()) {
                swap(arr[j], arr[j+1]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }
        cout << arr[i] << endl;
    }
}