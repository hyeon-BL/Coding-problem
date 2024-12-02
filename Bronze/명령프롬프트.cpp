#include<iostream>
#include<vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<string> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
    
    string pattern = arr[0];
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < pattern.size(); j++) {
            if (pattern[j] != arr[i][j]) {
                pattern[j] = '?';
            }
        }
    }

    cout << pattern;
}