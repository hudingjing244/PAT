#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
    int n, m;
    char c;
    scanf("%d %c", &n, &c);
    m = round(((double)n) / 2);

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            printf("%c", c);
        else
        {
            printf("%c\n", c);
        }
    }

    for (int j = 0; j < m - 2; j++)
    {
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                printf("%c", c);
            else if (i == n - 1)
            {
                printf("%c\n", c);
            }
            else
            {
                printf(" ");
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i < n - 1)
            printf("%c", c);
        else
        {
            printf("%c\n", c);
        }
    }
    return 0;
}
