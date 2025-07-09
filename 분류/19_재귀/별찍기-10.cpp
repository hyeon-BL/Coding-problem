#include <iostream>
#include <vector>
using namespace std;

vector<string> generate_stars(int n)
{
    if (n == 1)
    {
        return {"*"};
    }

    vector<string> smaller_stars = generate_stars(n / 3);
    vector<string> result;

    // 위쪽 3줄
    for (const string &row : smaller_stars)
    {
        result.push_back(row + row + row);
    }

    // 중간 3줄
    for (const string &row : smaller_stars)
    {
        result.push_back(row + string(n / 3, ' ') + row);
    }

    // 아래쪽 3줄
    for (const string &row : smaller_stars)
    {
        result.push_back(row + row + row);
    }

    return result;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    vector<string> stars = generate_stars(N);
    for (const string &row : stars)
    {
        cout << row << '\n';
    }
    return 0;
}