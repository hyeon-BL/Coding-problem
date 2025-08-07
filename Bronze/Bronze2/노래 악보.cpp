#include <iostream>
#include <vector>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, Q;
    cin >> N >> Q;
    
    vector<int> ls;
    for (int I = 0; I < N; I++) {
        int l;
        cin >> l;
        ls.push_back(l);
    }
    while(Q--) {
        int q, temp;
        cin >> q;
        temp = q;
        for (int i = 0; i < N; i++) {
            temp -= ls[i];
            if (temp < 0) {
                cout << i + 1 << '\n';
                break;
            }
        }
    }
    return 0;
}
