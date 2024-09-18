#include<iostream>
using namespace std;

int main() {
    string element;
    string arr[6] = {"         ,r'\"7", "r`-_   ,'  ,/", " \\. \". L_r'", "   `~\\/", "      |", "      |"};
    for (const string& element : arr) {
        cout << element << '\n';
    }
}