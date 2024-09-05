#include <iostream>
#include <list>
using namespace std;

string possible(list<int> sortedL, list<int> rawL) {
    list<int> s;
    string result = "";
    while (!rawL.empty()) {
        if (sortedL.front() <= rawL.front()) {
            s.push_back(sortedL.front());
            sortedL.pop_front();
            result += "+";
        }
        else if (s.back() == rawL.front()) {
            s.pop_back();
            rawL.pop_front();
            result += "-";
        }
        else {
            return "NO";
        }
    }
    return result;
}

int main() {
    int n;
    list<int> L;
    list<int> rL;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        L.push_back(x);
    }
    rL = L;
    L.sort();

    

    for (char c : possible(L, rL)) {
        cout << c << '\n';
    }
    return 0;
}


/*
12345678
1234
-> 43
1256
-> 436
12578
-> 43687521
*/