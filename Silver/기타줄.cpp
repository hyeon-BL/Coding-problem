#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> v(M);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        v[i] = make_pair(a, b);
    }

    int bundle = 10000;
    int each = 10000;
    for (int i = 0; i < M; i++) {
        bundle = min(bundle, v[i].first);
        each = min(each, v[i].second);
    }
    int result = 0;
    while (N > 0) {
        if (N >= 6) {
            result += min(bundle, each * 6);
            N -= 6;
        }
        else {
            result += min(bundle, each * N);
            N = 0;
        }
    }
    cout << result;
}