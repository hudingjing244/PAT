#include<cstdio>
#include<cstring>

int main()
{
    int count[10]= {0};
    char in[1001];
    int len;

    scanf("%s", in);
    len = strlen(in);
    for (int i = 0; i < len;i++)
    {
        count[in[i] - '0']++;
    }

    for (int i = 0; i < 10;i++)
    {
        if(count[i]!=0)
            printf("%d:%d\n", i, count[i]);
    }

        return 0;
}