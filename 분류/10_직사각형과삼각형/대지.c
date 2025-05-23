#include <stdio.h>

int main()
{
    int N;
    int x[100001], y[100001];

    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }

    int max_x = -1e9, min_x = 1e9;
    int max_y = -1e9, min_y = 1e9;
    for (int i = 0; i < N; i++)
    {
        if (x[i] > max_x)
        {
            max_x = x[i];
        }
        if (x[i] < min_x)
        {
            min_x = x[i];
        }
        if (y[i] > max_y)
        {
            max_y = y[i];
        }
        if (y[i] < min_y)
        {
            min_y = y[i];
        }
    }

    if (max_x == -1e9 || min_x == 1e9)
        max_x = min_x = 0;
    if (max_y == -1e9 || min_y == 1e9)
        max_y = min_y = 0;

    int result = abs((max_x - min_x) * (max_y - min_y));
    printf("%d\n", result);
    return 0;
}