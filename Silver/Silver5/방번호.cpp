#include <iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string roomNumber;
    cin >> roomNumber;

    int count[10] = {
        0,
    };

    for (int i = 0; i < roomNumber.size(); i++)
    {
        count[roomNumber[i] - '0']++;
    }

    int sixNine = (count[6] + count[9] + 1) / 2; // 6과 9를 합쳐서 계산 (올림)

    count[6] = sixNine;
    count[9] = sixNine;

    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (count[i] > max)
        {
            max = count[i];
        }
    }

    cout << max;
}