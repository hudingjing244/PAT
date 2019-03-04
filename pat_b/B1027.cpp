#include <cmath>
#include <cstdio>

int main()
{
    int max;
    int N;
    int gap;
    char c;

    scanf("%d %c", &N, &c);
    max = sqrt((N + 1.0) * 2.0) - 1;
    if (max % 2 == 0)
        max -= 1;
    gap = N + 1 - (1 + max) * (1 + max) / 2;

    for (int i = max; i > 0; i -= 2)
    {
        for (int j = 0; j < (max - i) / 2; j++)
            printf(" ");
        for (int j = 0; j < i; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }

    for (int i = 3; i <= max; i += 2)
    {
        for (int j = 0; j < (max - i) / 2; j++)
            printf(" ");
        for (int j = 0; j < i; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }

    printf("%d", gap);
    getchar();
    getchar();
    return 0;
}