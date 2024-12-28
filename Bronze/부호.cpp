#include <iostream>
using namespace std;
int main()
{
    int T = 3;
    while (T--)
    {
        int N = 0;
        long long sum = 0, flow = 0;
        cin >> N;
        for (int i = 0; i < N; i++)
        {
            long long temp;
            cin >> temp;
            long long prev = sum;
            sum = sum + temp;
            if (temp > 0 && prev > 0 && sum < 0)
                flow++; // 오버플로우
            else if (temp < 0 && prev < 0 && sum > 0)
                flow--; // 언더플로우
        }
        if (flow == 0)
        { // flow == 0
            if (sum == 0)
                cout << '0' << endl;
            else
                cout << (sum > 0 ? '+' : '-') << endl;
        }
        else
        { // flow != 0
            cout << (flow > 0 ? '+' : '-') << endl;
        }
    }
}