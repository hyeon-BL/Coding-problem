#include<iostream>
using namespace std;

int main() {
    int as[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int des[8] = {8, 7, 6, 5, 4, 3, 2, 1};
    int input[8];
    string result = "";

    for (int i=0; i<8; i++) {
        cin >> input[i];
    }

    for (int i=0; i<8; i++) {
        if (as[i] == input[i]) {
            result += "a";
        }
        else if (des[i] == input[i]) {
            result += "d";
        }
        else {
            result = "mixed";
            break;
        }
    }
    if (result == "aaaaaaaa") {
        cout << "ascending";
    }
    else if (result == "dddddddd") {
        cout << "descending";
    }
    else {
        cout << "mixed";
    }
}