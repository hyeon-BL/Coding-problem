#include<iostream>
#include<list>
using namespace std;

list<char> stack;

void if_bracket(string s) {
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            stack.push_back(s[i]);
        }
        else if (s[i] == ')') {
            if (stack.back() == '(') {
                stack.pop_back();
            }
            else {
                cout << "no";
                return;
            }
        }
        else if (s[i] == ']') {
            if (stack.back() == '[') {
                stack.pop_back();
            }
            else {
                cout << "no";
                return;
            }
        }
    }
}

int main(){
    string s;
    list<string> l;
    while (s != ".") {
        cin >> s;
        l.push_back(s);
    }
    for (auto i = l.begin(); i != l.end(); i++) {
        if_bracket(*i);
    }
    if (stack.empty()) {
        cout << "yes";
    }
    else {
        cout << "no";
    }
}