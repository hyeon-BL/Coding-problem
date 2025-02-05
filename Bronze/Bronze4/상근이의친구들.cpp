#include <iostream>
#include <vector>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int M, F;
    while (1)
    {
        cin >> M >> F;
        if (M == 0 && F == 0)
        {
            break;
        }
        cout << M + F << '\n';
    }
}