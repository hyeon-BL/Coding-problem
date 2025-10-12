#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    int K = 1, count = 0;
    while (N > 0)
    {
        if (K > N)
            K = 1;
        N -= K;
        K++;
        count++;
    }
    cout << count << endl;
}