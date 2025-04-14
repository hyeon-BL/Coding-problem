#include <stdio.h>

int main()
{
    int arr[6] = {1, 1, 2, 2, 2, 8};
    int input[6] = {
        0,
    };
    int i = 0;

    for (i = 0; i < 6; i++)
    {
        scanf("%d", &input[i]);
    }
    for (i = 0; i < 6; i++)
    {
        printf("%d ", arr[i] - input[i]);
    }
}