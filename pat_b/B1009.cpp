#include <cstdio>

int main()
{
    int count = 0;
    char input[81][81];

    while (scanf("%s", input[count]) != EOF)
        count++;

        for (int i = count - 1; i > 0; i--)
        {
            printf("%s ", input[i]);
        }
    printf("%s", input[0]);
    getchar();
    getchar();

    return 0;
}