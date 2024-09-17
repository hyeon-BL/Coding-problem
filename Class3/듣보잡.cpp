#include<iostream>
#include<algorithm>
using namespace std;


int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int N, M;
    int count = 0;

    cin >> N >> M;
    string* N_arr = new string[N];
    string* M_arr = new string[M];
    string* result = new string[N + M];

    for (int i = 0; i < N; i++) {
        cin >> N_arr[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> M_arr[i];
    }

    sort(N_arr, N_arr + N); // O(NlogN)
    sort(M_arr, M_arr + M); // O(MlogM)

    for (int i = 0; i < N; i++) { // O(NlogM)
        int start = 0;
        int end = M - 1;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (N_arr[i] == M_arr[mid]) {
                result[count] = N_arr[i];
                count++;
                break;
            }
            else if (N_arr[i] < M_arr[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
    }
    if (count == 0) {
        cout << count;
        return 0;
    }

    cout << count << '\n';

    // sort(result, result + count);
    for (int i = 0; i < count; i++) {
        if (i != count - 1) {
            cout << result[i] << '\n';
        }
        else {
            cout << result[i];
        }
    }

    delete[] N_arr;
    delete[] M_arr;
    delete[] result;

    return 0;
}