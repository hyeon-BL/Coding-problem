#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    // Dynamically allocate a 2D array
    int** arr = new int*[N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[2];
    }

    // Input the coordinates
    for (int i = 0; i < N; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }

    // Sort the 2D array
    sort(arr, arr + N, [](const int* a, const int* b) { // Lambda function for sorting
        if (a[0] == b[0]) {
            return a[1] < b[1]; // If the x-coordinates are the same, sort by y-coordinates
        }
        return a[0] < b[0]; // Sort by x-coordinates
    });

    // Output the sorted coordinates
    for (int i = 0; i < N; i++) {
        cout << arr[i][0] << " " << arr[i][1] << '\n';
    }

    // Deallocate the 2D array
    for (int i = 0; i < N; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}