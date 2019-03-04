#include <cstdio>
#include <cstring>

int main()
{
    char num[10][5] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char suffix[6][6] = {"", " Shi", " Bai", " Qian", " Wan", " Yi"};

    int input;
    char digits[10];
    int len;
    char temp;

    scanf("%d", &input);
    if (input < 0)
    {
        input = -(input);
        printf("Fu ");
    }
    sprintf(digits, "%d", input);
    len = strlen(digits);
    for (int i = 0; i < len / 2; i++)
    {
        temp = digits[i];
        digits[i] = digits[len - 1 - i];
        digits[len - 1 - i] = temp;
    }
    int printCnt = 0;
    bool needzero = false;
    int indx;

    if (input == 0)
        printf("ling");
    else
    {

        for (len--; len >= 0; len--, printCnt++)
        {

            if (len % 4)
                indx = len % 4;
            else if (len == 8)
                indx = 5;
            else if (len == 4)
                indx = 4;
            else if (len == 0)
                indx = 0;

            if (digits[len] == '0')
            {
                needzero = true;
                if (input < 100000000 && len % 4 == 0)
                {
                    printf("%s", suffix[indx]);
                }
            }
            else
            {
                if (printCnt)
                    putchar(' ');
                if (needzero)
                {
                    printf("ling ");
                }
                printf("%s%s", num[digits[len] - '0'], suffix[indx]);

                needzero = false;
            }
        }
    }

    getchar();
    getchar();

    return 0;
}