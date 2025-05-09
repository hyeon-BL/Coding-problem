#include <stdio.h>

int isOne(int *arr)
{
    if (arr[0] == arr[1])
        return arr[2];
    else if (arr[0] == arr[2])
        return arr[1];
    else if (arr[1] == arr[2])
        return arr[0];
}

int main()
{
    int X[3], Y[3];
    for (int i = 0; i < 3; i++)
    {
        scanf("%d %d", &X[i], &Y[i]);
    }
    int X_result = isOne(X);
    int Y_result = isOne(Y);

    printf("%d %d", X_result, Y_result);
    return 0;
}