#include <cstdio>

int main()
{
    char base[10000];
    char *p = base;
    int exp;

    scanf("%[^E]E%d", base, &exp);

    if (*p++ == '-')
        putchar('-');

    if (exp >= 0)
    {
        putchar(*p++);
        for (p++; exp; exp--)
        {
            putchar(*p ? *p++ : '0');
        }
        if (*p)
        {
            putchar('.');
            while (*p)
                putchar(*p++);
        }
    }
    else
    {
        printf("0.");
        for (exp++; exp; exp++)
        {
            putchar('0');
        }
        while (*p)
        {
            if (*p != '.')
                putchar(*p++);
            else
            {
                p++;
            }
        }
    }

    getchar();
    getchar();

    return 0;
}