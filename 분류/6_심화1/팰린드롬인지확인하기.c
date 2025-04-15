#include <stdio.h>
#include <string.h>

int main()
{
    char word[101];
    scanf("%s", word);
    int len = strlen(word);
    for (int i = 0; i < len / 2; i++)
    {
        if (word[i] != word[len - 1 - i])
        {
            printf("0");
            return 0;
        }
    }
    printf("1");
    return 0;
}