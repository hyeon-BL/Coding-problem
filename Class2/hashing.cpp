#include<iostream>
using namespace std;

// djb2 hash function
unsigned long get_hash(string str)
{
    unsigned long hash = 0;
    int c;
    for (int i = (int)str.size() - 1; i >= 0; i--)
    {
        c = str[i] - 'a' + 1;
        hash = (((hash << 5) - hash) + c) % 1234567891; // hash * 31 + c (shift -> faster than multiply)
        continue;
    }
    return hash % 1234567891;
}



int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int L;
    string str;
    cin >> L;
    cin >> str;

    unsigned long sum = 0;
    sum = get_hash(str);
    cout << sum;

}