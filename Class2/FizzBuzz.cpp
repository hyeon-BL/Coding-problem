#include<iostream>
using namespace std;

int main() {
    auto s1 = 0, s2 = 0, s3 = 0;
    cin >> s1;
    cin >> s2;
    cin >> s3;
    if (typeid(s1) == typeid(int)) {
        s1 += 3;
        if (s1 % 3 == 0 && s1 % 5 == 0) {
            cout << "FizzBuzz";
        }
        else if (s1 % 3 == 0) {
            cout << "Fizz";
        }
        else if (s1 % 5 == 0) {
            cout << "Buzz";
        }
        else {
            cout << s1;
        }
    }
    else if (typeid(s2) == typeid(int)) {
        s2 += 2;
        if (s2 % 3 == 0 && s2 % 5 == 0) {
            cout << "FizzBuzz";
        }
        else if (s2 % 3 == 0) {
            cout << "Fizz";
        }
        else if (s2 % 5 == 0) {
            cout << "Buzz";
        }
        else {
            cout << s2;
        }
    }
    else if (typeid(s3) == typeid(int)) {
        s3 += 1;
        if (s3 % 3 == 0 && s3 % 5 == 0) {
            cout << "FizzBuzz";
        }
        else if (s3 % 3 == 0) {
            cout << "Fizz";
        }
        else if (s3 % 5 == 0) {
            cout << "Buzz";
        }
        else {
            cout << s3;
        }
    }
}