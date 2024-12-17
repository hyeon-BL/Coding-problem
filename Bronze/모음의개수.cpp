#include<iostream>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    while(true) {
        string s;
        int cnt = 0;
        getline(cin, s);
        if (s == "#") {
            break;
        }

        for (int i = 0; i < s.size(); i++) {
            if (string("aeiouAEIOU").find(s[i]) != string::npos) {
                cnt++;
            }
        }
        cout << cnt << '\n';
        
    }
}