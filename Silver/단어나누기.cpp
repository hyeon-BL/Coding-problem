#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string word;
    cin >> word;

    string temp = "";
    string result = "";
    for (int i = 0; i < word.size(); i++) {
        for (int j = i + 1; j < word.size(); j++) {
            string part1 = word.substr(0, i);
            string part2 = word.substr(i, j - i);
            string part3 = word.substr(j);
            reverse(part1.begin(), part1.end());
            reverse(part2.begin(), part2.end());
            reverse(part3.begin(), part3.end());
            if (part1 == "" || part2 == "" || part3 == "") {
                continue;
            }
            temp = part1 + part2 + part3;
            if (result == "") {
                result = temp;
            } else if (result > temp) { // compare lexicographically
                result = temp;
            }
        }
    }
    cout << result;
    return 0;
}