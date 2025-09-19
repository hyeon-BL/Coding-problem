#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

struct Point
{
    double x, y;
};

double direction_x[] = {0, sqrt(2) / 2, 1, sqrt(2) / 2, 0, -sqrt(2) / 2, -1, -sqrt(2) / 2};
double direction_y[] = {1, sqrt(2) / 2, 0, -sqrt(2) / 2, -1, -sqrt(2) / 2, 0, sqrt(2) / 2};

int ccw(Point a, Point b, Point c)
{
    double op = a.x * b.y + b.x * c.y + c.x * a.y;
    op -= (a.y * b.x + b.y * c.x + c.y * a.x);
    if (op > 0)
        return 1; // counter clockwise
    if (op < 0)
        return -1; // clockwise
    return 0;      // collinear
}

// 중복을 허용한 순열 생성 함수
void generate_permutations(vector<double> &stats, vector<bool> &used, vector<double> &current, vector<vector<double>> &permutations)
{
    if (current.size() == stats.size())
    {
        permutations.push_back(current);
        return;
    }

    for (int i = 0; i < stats.size(); i++)
    {
        if (!used[i])
        {
            used[i] = true;
            current.push_back(stats[i]);
            generate_permutations(stats, used, current, permutations);
            current.pop_back();
            used[i] = false;
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<double> stats(8);
    for (int i = 0; i < 8; i++)
        cin >> stats[i];

    // 중복을 허용한 순열 생성
    vector<bool> used(8, false);
    vector<double> current;
    vector<vector<double>> permutations;
    generate_permutations(stats, used, current, permutations);

    int count = 0;
    for (const auto &perm : permutations)
    {
        Point stat_pos[8];
        for (int i = 0; i < 8; i++)
        {
            stat_pos[i].x = perm[i] * direction_x[i];
            stat_pos[i].y = perm[i] * direction_y[i];
        }

        // Convex 확인
        bool isConvex = true;
        int firstRes = ccw(stat_pos[0], stat_pos[1], stat_pos[2]);
        for (int i = 0; i < 8; i++)
        {
            int res = ccw(stat_pos[i], stat_pos[(i + 1) % 8], stat_pos[(i + 2) % 8]);
            if (res != firstRes)
            {
                isConvex = false;
                break;
            }
        }
        if (isConvex)
            count++;
    }

    cout << count << "\n";
    return 0;
}