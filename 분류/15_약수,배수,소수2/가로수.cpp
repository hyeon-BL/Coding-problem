#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b)
{
    int gcd;
    int temp_a = a;
    int temp_b = b;
    while (temp_b != 0)
    {
        gcd = temp_b;
        temp_b = temp_a % temp_b;
        temp_a = gcd;
    }
    return gcd;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    vector<int> trees(N);
    for (int i = 0; i < N; i++)
    {
        cin >> trees[i];
    }

    int total_gcd = trees[1] - trees[0];
    for (int i = 2; i < N; i++)
    {
        total_gcd = gcd(total_gcd, trees[i] - trees[i - 1]);
    }

    int count = (trees[N - 1] - trees[0]) / total_gcd + 1;
    cout << count - N << '\n';
}