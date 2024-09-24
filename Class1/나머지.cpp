#include<iostream>
#include<set>
using namespace std;

int main() {
    int A[10];
    set<int> rem;

    for (int i=0; i<10; i++) {
        cin >> A[i];
        rem.insert(A[i] % 42);
    }

    cout << rem.size();
    
}