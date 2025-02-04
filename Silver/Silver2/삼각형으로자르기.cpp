#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

double calculateArea(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
    return abs(a.first * (b.second - c.second) + b.first * (c.second - a.second) + c.first * (a.second - b.second)) / 2.0;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // N: 점 개수
    cin >> N;
    vector<pair<int, int>> point(N); // 점의 좌표
    for (int i = 0; i < N; i++)
    {
        cin >> point[i].first >> point[i].second;
    }

    double maxArea = 0;
    pair<int, int> p1, p2, p3;

    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            for (int k = j + 1; k < N; k++)
            {
                double area = calculateArea(point[i], point[j], point[k]);
                if (area > maxArea)
                {
                    maxArea = area;
                    p1 = point[i];
                    p2 = point[j];
                    p3 = point[k];
                }
            }
        }
    }
    fixed(cout);
    cout.precision(9);
    cout << maxArea;
}