#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, double> grade_to_score = {
    {"A+", 4.5},
    {"A0", 4.0},
    {"B+", 3.5},
    {"B0", 3.0},
    {"C+", 2.5},
    {"C0", 2.0},
    {"D+", 1.5},
    {"D0", 1.0},
    {"F", 0.0}};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string subject, grade;
    double credit, total_score = 0.0, total_credit = 0.0;

    int count = 20;
    while (count--)
    {
        cin >> subject >> credit >> grade;
        if (grade != "P")
        {
            total_score += credit * grade_to_score[grade];
            total_credit += credit;
        }
    }

    cout.precision(6);
    cout << fixed << total_score / total_credit;
}