#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    int count = 0;
    string str;
    cin >> N;

    for (int i=1; i<N; i++) {
        str = to_string(i);
        for (int j=0; j<str.length(); j++) {
            count += (int)str[j] - 48;
        }
        count += i;
        if (count == N) {
            cout << i;
            return 0;
        }
        else {
            count = 0;
        }
    }
    cout << 0;
}