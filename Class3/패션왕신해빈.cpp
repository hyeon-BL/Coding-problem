#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int cases, n;
    string item, type;
    cin >> cases;
    for (int i = 0; i < cases; i++) {
        cin >> n;
        unordered_map<string, int> clothes;
        for (int j = 0; j < n; j++) {
            cin >> item >> type;
            clothes[type]++;
        }
        int result = 1;
        for (auto& c : clothes) {
            result *= (c.second + 1); // +1 for the option of not wearing an item of this type
        }
        result--; // subtract the case where no clothes are worn
        cout << result << '\n';
    }
}


/*
2
3
hat headgear 
sunglasses eyewear
turban headgear -> headgear 2개, eyewear 1개, (2+1)*(1+1) - 1 = 5
3
mask face
sunglasses face
makeup face -> face 3개, (3+1) - 1 = 3
*/