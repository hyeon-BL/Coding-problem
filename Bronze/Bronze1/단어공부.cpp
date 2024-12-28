#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string str;
    int arr[26] = {0, };

    cin >> str;
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    
    for (int i = 0; i < str.length(); i++) {
        arr[str[i] - 'A']++;
    }

    int carr[26];
    copy(arr, arr + 26, carr);
    sort(arr, arr + 26, greater<int>());
    if (arr[0] == arr[1]) {
        cout << "?" << endl;
    } else {
        cout << (char)('A' + (max_element(carr, carr + 26) - carr)) << endl;
    }
}