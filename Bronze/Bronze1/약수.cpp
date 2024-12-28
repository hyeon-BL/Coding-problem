#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> divisors(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> divisors[i];
    }
    
    sort(divisors.begin(), divisors.end());
    
    int original_number = divisors.front() * divisors.back();
    cout << original_number << endl;
    
    return 0;
}
