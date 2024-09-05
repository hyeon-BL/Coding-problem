#include <iostream>
#include <vector> // vector는 메모리를 연속적으로 할당하기 때문에 배열처럼 사용 가능, 메모리 사용량이 적음
#include <algorithm> // for sort
using namespace std;

string possible(vector<int>& sortedL, vector<int>& rawL) {
    vector<int> s;
    string result = "";
    size_t sortedIndex = 0;
    size_t rawIndex = 0;

    while (rawIndex < rawL.size()) {
        if (sortedIndex < sortedL.size() && sortedL[sortedIndex] <= rawL[rawIndex]) {
            s.push_back(sortedL[sortedIndex]);
            sortedIndex++;
            result += "+";
        }
        else if (!s.empty() && s.back() == rawL[rawIndex]) {
            s.pop_back();
            rawIndex++;
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
    vector<int> L;
    cin >> n;
    L.reserve(n);

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        L.push_back(x);
    }

    vector<int> rL = L;
    sort(L.begin(), L.end());

    string result = possible(L, rL);
    for (size_t i = 0; i < result.size(); ++i) {
        if (result[i] == 'N') {
            cout << "NO";
            return 0;
        }
        cout << result[i];
        if (i != result.size() - 1) {
            cout << '\n';
        }
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