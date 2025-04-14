#include <iostream>
#include <string>
using namespace std;

int reversed(string s)
{
    char temp = s[0];
    s[0] = s[s.size() - 1];
    s[s.size() - 1] = temp;

    return stoi(s);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string n1, n2;
    cin >> n1 >> n2;

    int n1_reversed = reversed(n1);
    int n2_reversed = reversed(n2);

    if (n1_reversed > n2_reversed)
    {
        cout << n1_reversed;
    }
    else
    {
        cout << n2_reversed;
    }
}