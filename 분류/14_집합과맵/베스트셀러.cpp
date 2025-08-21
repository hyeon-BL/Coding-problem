#include <iostream>
#include <map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    map<string, int> books; // 사전순 정렬
    for (int i = 0; i < N; i++) {
        string book;
        cin >> book;

        if (books.find(book) == books.end()) {
            books[book] = 1;
        }
        else {
            books[book]++;
        }
    }

    int bestseller_cnt = 0;
    string bestseller;
    for (auto iter = books.begin(); iter != books.end(); iter++) {
        if (iter -> second > bestseller_cnt) {
            bestseller = iter -> first;
            bestseller_cnt = iter -> second;
        }
    }
    cout << bestseller;
    return 0;
}
