#include <string>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int solution(int n, int w, int num)
{
    int answer = 0;

    int h = n % w == 0 ? n / w : n / w + 1;

    vector<int> layer[11];
    for (int i = 1; i <= w; i++)
    {
        int temp = i;
        int cnt = 1;
        while (temp <= n)
        {
            layer[i].push_back(temp);
            if (cnt % 2 == 1)
                temp += 2 * w - 1 - 2 * (i - 1);
            else
                temp += 1 + 2 * (i - 1);
            cnt++;
        }
    }

    for (int i = 1; i <= w; i++)
    {
        auto it = find(layer[i].begin(), layer[i].end(), num);
        if (it != layer[i].end())
        {
            int idx = it - layer[i].begin();
            answer = layer[i].size() - idx;
        }
    }

    return answer;
}

int main()
{
    int n, w, num;
    cin >> n >> w >> num;

    cout << solution(n, w, num) << endl;

    return 0;
}