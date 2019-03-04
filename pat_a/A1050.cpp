#include<cstdio>

int main()
{
    char str[10001];
    bool subtract[128] = {0};
    char c,*p=str;
    scanf("%[^\n]", str);
    getchar();
    while((c=getchar())!='\n')
        subtract[c] = true;
    while(*p)
    {
        if(!subtract[*p])
            putchar(*p);
        p++;
    }

    getchar();
    getchar();
    return 0;
    
}