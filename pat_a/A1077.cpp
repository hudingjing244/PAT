#include <cstdio>
#include <cstring>

int main()
{
    int n;
    char input[100][257];
    int len;
    int minLen = 257;
    char temp;

    int commonLen = 0;
    int flag = 0;

    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {

        scanf("%[^\n]", input[i]);
        getchar();
        len = strlen(input[i]);
        if (len < minLen)
            minLen = len;
        for (int j = 0; j < len / 2; j++)
        {
            temp = input[i][j];
            input[i][j] = input[i][len - 1 - j];
            input[i][len - 1 - j] = temp;
        }
    }
    for (int i = 0; i < minLen; i++)
    {

        for (int j = 0; j < n - 1; j++)
        {
            if (input[j][i] != input[j + 1][i])
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
        {
            commonLen = i;
            break;
        }
    }
    if (flag == 0)
    {
        commonLen = minLen;
    }

    if (commonLen)
    {
        for (; commonLen; commonLen--)
            putchar(input[0][commonLen - 1]);
    }
    else
    {
        printf("nai");
    }

    getchar();
    getchar();
    return 0;
}