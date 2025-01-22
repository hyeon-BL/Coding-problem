#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string arr;
    cin >> arr;

    int *num = new int[arr.size()];
    for (int i = 0; i < arr.size(); i++)
    {
        num[i] = arr[i] - '0';
    }
    sort(num, num + arr.size(), greater<int>());
    for (int i = 0; i < arr.size(); i++)
    {
        cout << num[i];
    }
}