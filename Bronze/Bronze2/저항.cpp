#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, int> color_to_value = {
    {"black", 0}, {"brown", 1}, {"red", 2}, {"orange", 3}, {"yellow", 4}, {"green", 5}, {"blue", 6}, {"violet", 7}, {"grey", 8}, {"white", 9}};

unordered_map<string, long long> color_to_multiplier = {
    {"black", 1}, {"brown", 10}, {"red", 100}, {"orange", 1000}, {"yellow", 10000}, {"green", 100000}, {"blue", 1000000}, {"violet", 10000000}, {"grey", 100000000}, {"white", 1000000000}};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    string first_color, second_color, third_color;
    cin >> first_color >> second_color >> third_color;

    int value = color_to_value[first_color] * 10 + color_to_value[second_color];
    long long multiplier = color_to_multiplier[third_color];

    cout << value * multiplier << '\n';

    return 0;
}
