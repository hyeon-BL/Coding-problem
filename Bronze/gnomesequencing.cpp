#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N, prev;
    vector<int> v(3);

    cin >> N;
    cout << "Gnomes:\n";
    while (N--)
    {
        cin >> v[0] >> v[1] >> v[2];
        if (v[0] >= v[1] && v[1] >= v[2])
            cout << "Ordered\n";
        else if (v[0] <= v[1] && v[1] <= v[2])
            cout << "Ordered\n";
        else
            cout << "Unordered\n";
    }
}