#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

char dictionary[200002][10], puzzle[10];
int pzl[26], alpha[26], maxCount, minCount;

bool canFormWord(const char *puzzle, const char *word)
{
    int temp[26] = {0};
    memset(temp, 0, sizeof(temp));
    for (int i = 0; word[i] != '\0'; i++)
    {
        temp[word[i] - 'A']++;
        if (temp[word[i] - 'A'] > pzl[word[i] - 'A'])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int dictSize = 0;
    while (true)
    {
        cin >> dictionary[dictSize];
        if (dictionary[dictSize][0] == '-')
            break;
        dictSize++;
    }

    while (true)
    {
        cin >> puzzle;
        if (puzzle[0] == '#')
            break;

        memset(pzl, 0, sizeof(pzl));
        memset(alpha, 0, sizeof(alpha));

        for (int i = 0; puzzle[i] != '\0'; i++)
        {
            pzl[puzzle[i] - 'A']++;
        }

        for (int i = 0; i < dictSize; i++)
        {
            int temp[26] = {0};
            if (canFormWord(puzzle, dictionary[i]))
            {
                for (int j = 0; dictionary[i][j] != '\0'; j++)
                {
                    if (temp[dictionary[i][j] - 'A'] == 0)
                    {
                        alpha[dictionary[i][j] - 'A']++;
                    }
                    temp[dictionary[i][j] - 'A'] = 1;
                }
            }
        }

        maxCount = 0;
        minCount = INT_MAX;
        for (int i = 0; i < 26; i++)
        {
            if (pzl[i] > 0)
            { // 퍼즐에 있는 알파벳만 고려
                if (alpha[i] > maxCount)
                    maxCount = alpha[i];
                if (alpha[i] < minCount)
                    minCount = alpha[i];
            }
        }

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] == minCount && pzl[i] > 0)
            {
                cout << char(i + 'A');
            }
        }
        cout << " " << minCount << " ";
        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] == maxCount && pzl[i] > 0)
            {
                cout << char(i + 'A');
            }
        }
        cout << " " << maxCount << "\n";
    }

    return 0;
}