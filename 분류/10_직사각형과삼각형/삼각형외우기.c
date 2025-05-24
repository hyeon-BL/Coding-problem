#include <stdio.h>

int main()
{
    int A, B, C;
    scanf("%d %d %d", &A, &B, &C);

    if (A + B + C == 180)
    {
        if (A == 60 && B == 60 && C == 60)
        {
            printf("Equilateral\n");
        }
        else if (A == B || B == C || A == C)
        {
            printf("Isosceles\n");
        }
        else
        {
            printf("Scalene\n");
        }
    }
    else
    {
        printf("Error\n");
    }
}