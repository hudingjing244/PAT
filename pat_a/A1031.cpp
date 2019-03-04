#include <cstdio>
#include <cstring> 



int main()
{
    int n1, n2, N;
    char str[90];
    scanf("%s", str);
    N = strlen(str);
    n1 = (N + 2.0) / 3.0;
    n2 = N + 2 - 2 * n1;

    for (int i = 0; i < n1; i++)
    {
        printf("%c", str[i]);
        if (i < n1 - 1)
        {
            for (int j = 0; j < n2 - 2; j++)
            {
                printf(" ");
            }
        }
        else
        {
            for (int j = 1; j <= n2 - 2; j++)
            {
                printf("%c", str[i + j]);
            }
        }

        printf("%c\n", str[N - i - 1]);
    }

    getchar();
    getchar();

    return 0;
}