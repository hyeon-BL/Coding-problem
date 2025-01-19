#include<iostream>
#include<unordered_map>
#include<set>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int** arr = new int* [N];
    for (int i = 0; i < N; i++) {
        arr[i] = new int[5]; // Allocate memory for each row
        for (int j = 0; j < 5; j++) {
            cin >> arr[i][j]; // Read each element
        }
    }

    unordered_map<int, set<int>> m;
    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < N; i++) {
            for (int k = i + 1; k < N; k++) {
                if (arr[i][j] == arr[k][j]) {
                    m[i].insert(k);
                    m[k].insert(i);
                }
            }
        }
    }

    int max = 0;
    int maxIndex = 0;
    for (int i = 0; i < N; i++) {
        if (m[i].size() > max) {
            max = m[i].size();
            maxIndex = i;
        }
    }
    cout << maxIndex + 1;
}