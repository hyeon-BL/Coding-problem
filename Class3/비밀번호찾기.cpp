#include<iostream>
#include<unordered_map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    unordered_map<string, string> password_map;
    for (int i = 0; i < N; i++) {
        string site, password;
        cin >> site >> password;
        password_map[site] = password;
    }
    for (int i = 0; i < M; i++) {
        string site;
        cin >> site;
        cout << password_map[site] << '\n';
    }
}