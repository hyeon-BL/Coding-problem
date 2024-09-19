#include<iostream>
using namespace std;

int main() {
    int arr[9];
    int max = 0;
    int index = 0;

    for (int i=0; i<9; i++) {
        cin >> arr[i];
    }

    for (int i=0; i<9; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }

    cout << max << endl << index+1;

}