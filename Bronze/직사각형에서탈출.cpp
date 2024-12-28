#include <iostream>
using namespace std;

int main()
{
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int min_x = x < w - x ? x : w - x;
    int min_y = y < h - y ? y : h - y;

    cout << (min_x < min_y ? min_x : min_y);
}