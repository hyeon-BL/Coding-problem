#include<iostream>
#include<string>
#include<list>
using namespace std;


void if_bracket(string s) {
    list<char> stack = {};
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[') {
            stack.push_back(s[i]);
        }
        else if (s[i] == ')') {
            if (stack.back() == '(') {
                stack.pop_back();
            }
            else {
                cout << "no" << endl;
                return;
            }
        }
        else if (s[i] == ']') {
            if (stack.back() == '[') {
                stack.pop_back();
            }
            else {
                cout << "no" << endl;
                return;
            }
        }
    }
    if (stack.empty()) {
        cout << "yes" << endl;
    }
    else {
        cout << "no" << endl;
    }
}

int main(){
    string s;
    list<string> l;
    while (s != ".") {
        getline(cin, s);
        l.push_back(s);
    }
    for (auto i = l.begin(); i != l.end(); i++) {
        if (*i == ".") {
            break;
        }
        if_bracket(*i);
    }
}