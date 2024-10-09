#include<iostream>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int A, B, V;
    int day = 0;
    cin >> A >> B >> V;

    day = (V - B) / (A - B);
    if ((V - B) % (A - B) != 0) {
        day++;
    }
    cout << day;

}