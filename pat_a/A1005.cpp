#include<cstdio>
#include<cstring>

int main()
{
    char digits[10][6] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    int sum;
    
    char input[102];
    char *p = input;

    char ans[5];

    scanf("%s", input);
    while(*p)
    {
        sum = sum + (*p - '0');
        p++;
    }
    sprintf(ans, "%d", sum);

    printf("%s", digits[ans[0] - '0']);
    for (p = ans + 1; *p;p++)
    {
        printf(" %s", digits[*p - '0']);
    }

    getchar();
    getchar();
    return 0;
}