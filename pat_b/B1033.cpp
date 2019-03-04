#include<cstdio>

int main()
{
    bool broken[128] = {false};
    bool notShift = false;
    char str[100001];
    char c;
    while((c=getchar())!='\n')
    {
        broken[(int)c] = true;
        if(c=='+')
            notShift = true;
    }
    scanf("%s", str);
    int printCnt = 0;
    for (char *p = str;*p;p++)
    {
        c = *p;
        if(c>='a'&&c<='z')
            c = c - 'a' + 'A';

        if(broken[(int)c]||(*p>='A'&&*p<='Z'&&broken[(int)'+']))
            continue;
        putchar(*p);
        printCnt++;
    }
    if(!printCnt)
        putchar('\n');

    getchar();
    getchar();

    return 0;
}