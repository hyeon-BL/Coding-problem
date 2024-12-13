#include<iostream>
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


    int count0 = 0, count1 = 0, countMinus1 = 0;
    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) count0++;
        else if (arr[i] == 1) count1++;
        else if (arr[i] == -1) countMinus1++;
    }

    if (count0 * 2 >= N) {
        cout << "INVALID";
    }

    else if (count1 > countMinus1) {
        cout << "APPROVED";
    }

    else {
        cout << "REJECTED";
    }
    return 0;
}