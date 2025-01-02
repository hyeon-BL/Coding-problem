#include <iostream>
using namespace std;

int main()
{
    bool students[30] = {false};
    for (int i = 0; i < 28; i++)
    {
        int student_number;
        cin >> student_number;
        students[student_number - 1] = true;
    }

    for (int i = 0; i < 30; i++)
    {
        if (!students[i])
        {
            cout << i + 1 << "\n";
        }
    }
}