#include<iostream>
using namespace std;

int main() {
    int N, score = 0;
    string s;
    int count = 1;
    

    cin >> N;

    for (int i=0; i < N; i++) {
        cin >> s;
        for (int j=0; j < s.length(); j++) {
            if (s[j] == 'O') {
                score += count;
                count++;
            } else {
                count = 1;
            }
        }
        cout << score << endl;
        score = 0;
        count = 1;
    }
}