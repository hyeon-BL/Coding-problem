#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    while (N--)
    {
        long long Ti;
        cin >> Ti;
        map<long long, int> count;

        long long max = -1;
        long long maxIndex = 0;

        for (int i = 0; i < Ti; i++)
        {
            long long soldier;
            cin >> soldier;
            count[soldier]++;
            if (count[soldier] > max)
            {
                max = count[soldier];
                maxIndex = soldier;
            }
        }

        if (max <= Ti / 2)
        {
            cout << "SYJKGW\n";
        }
        else
        {
            cout << maxIndex << "\n";
        }

        // 메모리 초기화
        count.clear();
    }
}

/*
long과 int는 똑같이 4바이트이다.
따라서 long long을 사용해야 한다.
*/