#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int operators[4]; // +, -, *, /
vector<int> arr;

int calculate(int a, int b, int op)
{
    if (op == 0)
        return a + b; // +
    else if (op == 1)
        return a - b; // -
    else if (op == 2)
        return a * b; // *
    else
        return a / b; // /
}

vector<int> getAllResults(int idx, int current)
{
    if (idx == int(arr.size()))
    {
        return {current};
    }

    vector<int> results;
    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            vector<int> nextResults = getAllResults(idx + 1, calculate(current, arr[idx], i));
            results.insert(results.end(), nextResults.begin(), nextResults.end());
            operators[i]++;
        }
    }
    return results;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;

    arr.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 4; i++)
    {
        cin >> operators[i];
    }

    vector<int> results = getAllResults(1, arr[0]);
    int maxResult = *max_element(results.begin(), results.end());
    int minResult = *min_element(results.begin(), results.end());
    cout << maxResult << "\n"
         << minResult << "\n";
    return 0;
}