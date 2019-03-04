#include <cstdio>
#include <map>
using namespace std;

int main()
{
    char originStr[81];
    char typedStr[81];

    map<char, int> alreadyPrint;

    scanf("%s", originStr);
    for (char *p = originStr; *p; p++)
    {
        if (*p >= 'a' && *p <= 'z')
            *p = *p - 'a' + 'A';
    }
    getchar();
    scanf("%s", typedStr);
    for (char *p = typedStr; *p; p++)
    {
        if (*p >= 'a' && *p <= 'z')
            *p = *p - 'a' + 'A';
    }

    char *op = originStr, *tp = typedStr;
    while (*op)
    {
        if (*tp != *op)
        {
            if (alreadyPrint[*op] == 0)
            {
                alreadyPrint[*op] = 1;
                putchar(*op);
            }
            op++;
        }
        else
        {
            op++;
            tp++;
        }
    }

    getchar();
    getchar();

    return 0;
}