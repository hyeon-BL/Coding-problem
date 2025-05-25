#include <stdio.h>
int main()
{
    while (1)
    {
        int A, B, C;
        scanf("%d %d %d", &A, &B, &C);
        if (A == 0 && B == 0 && C == 0)
        {
            break;
        }

        if (A + B > C && A + C > B && B + C > A)
        {
            if (A == B && B == C)
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
            printf("Invalid\n");
        }
    }
}