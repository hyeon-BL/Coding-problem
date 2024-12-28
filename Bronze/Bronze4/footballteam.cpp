#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    while (getline(cin, line))
    {
        if (cin.eof())
            break;

        for (int i = 0; i < line.size(); i++)
        {
            if (line[i] == 'i')
                cout << 'e';
            else if (line[i] == 'e')
                cout << 'i';
            else if (line[i] == 'I')
                cout << 'E';
            else if (line[i] == 'E')
                cout << 'I';
            else
                cout << line[i];
        }
        cout << '\n';
    }
    return 0;
}