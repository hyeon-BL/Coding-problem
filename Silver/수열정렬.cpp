#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<pair<int, int>> v(N);

    for (int i = 0; i < N; i++) {
        int a;
        cin >> a;
        v[i] = {a, i};
    }

    sort(v.begin(), v.end());

    vector<int> result(N);
    for (int i = 0; i < N; i++) {
        result[v[i].second] = i;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << ' ';
    }

    return 0;
}