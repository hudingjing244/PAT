#include <cstdio>
#include <cstring>

int main()
{

    char s[4][61];
    char weekday[7][4] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        scanf("%s", &s[i][0]);
    }

    i = 0;

    while (true)
    {
        if (s[0][i] == s[1][i] && s[0][i] >= 'A' && s[0][i] <= 'G')
        {
            printf("%s ", weekday[s[0][i] - 'A']);
            break;
        }
        i++;
    }

    while (true)
    {
        i++;
        if (s[0][i] == s[1][i])

        {
            if (s[0][i] >= '0' && s[0][i] <= '9')
            {
                printf("0%d:", s[0][i] - '0');
                break;
            }
            else if (s[0][i] >= 'A' && s[0][i] <= 'N')
            {
                printf("%d:", s[0][i] - 'A' + 10);
                break;
            }
        }
    }

    i = 0;
    while (true)
    {
        if (s[2][i] == s[3][i] && ((s[2][i] >= 'a' && s[2][i] <= 'z') || (s[2][i] >= 'A' && s[2][i] <= 'Z')))
        {
            printf("%02d", i);
            break;
        }

        i++;
    }
    getchar();
    getchar();
    return 0;
}