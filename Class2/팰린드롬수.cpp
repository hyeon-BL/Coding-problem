#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num) {
    string str = to_string(num);
    int len = str.length();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int count = 0;
    int stop;
    int arr[100000] ; 

    while (true) {
        cin >> stop;
        if (stop == 0) break;
        else arr[count] = stop;
        count++;
    }

    for (int i = 0; i < count; i++) {
        if (isPalindrome(arr[i])) {
            cout << "yes" << '\n';
        } else {
            cout << "no" << '\n';
        }
    }

    return 0;
}