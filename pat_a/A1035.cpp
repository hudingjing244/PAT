#include <cstdio>

typedef struct
{
    char name[11];
    char pwd[11];
    bool modified = false;
} users;

int main()
{
    users info[1000];
    int n, m = 0;
    char *p = info[0].pwd;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s", info[i].name, info[i].pwd);
    }

    for (int i = 0; i < n; i++)
    {
        p = info[i].pwd;
        while (*p)
        {
            if (*p == '1')
            {
                *p = '@';
                info[i].modified = true;
            }

            else if (*p == '0')
            {
                *p = '%';
                info[i].modified = true;
            }

            else if (*p == 'l')
            {
                *p = 'L';
                info[i].modified = true;
            }

            else if (*p == 'O')
            {
                *p = 'o';
                info[i].modified = true;
            }
            p++;
        }
        if (info[i].modified)
            m++;
    }

    if (m == 0)
    {
        if (n == 1)
            printf("There is 1 account and no account is modified\n");
        else
            printf("There are %d accounts and no account is modified\n", n);
    }
    else
    {
        printf("%d\n", m);
        for (int i = 0; i < n; i++)
        {
            if (info[i].modified)
                printf("%s %s\n", info[i].name, info[i].pwd);
        }
    }

    getchar();
    getchar();

    return 0;
}