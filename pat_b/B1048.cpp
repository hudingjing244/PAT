#include <cstdio>
#include <cstring>


int main()
{
    char tempa[101], tempb[101],temp[101];
    char *a, *b;
    int len1, len2, len;
    int flag = 1;
    char mod13[13] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'J', 'Q', 'K'};
    scanf("%s%s", tempa, tempb);
    len1 = strlen(tempa);
    len2 = strlen(tempb);
    if(len1>len2)
    {
        len = len1;
        a = tempa;
        b = temp;
        for (int i = 0; i < (len1 - len2);i++)
        {
            b[i] = '0';
        }
        for (int i = 0; i < len2;i++)
        {
            b[i + len1 - len2] = tempb[i];
        }
    }
    else
    {
        len = len2;
        a = temp;
        b = tempb;
               for (int i = 0; i < (len2 - len1);i++)
        {
            a[i] = '0';
        }
        for (int i = 0; i < len1;i++)
        {
            a[i + len2 - len1] = tempa[i];
        }
    }
   flag= len % 2 ? 1 : 2;
    for (int i=0; i<len;i++)
    {
        if(flag==1)
        {
            putchar(mod13[((b[i] - '0') + (a[i] - '0')) % 13]);
            flag = 2;
        }
        else
        {
            printf("%d", ((b[i] - '0') -(a[i] - '0')) >= 0 ? ((b[i] - '0') - (a[i] - '0')) : ((b[i] - '0') - (a[i] - '0')) + 10);
            flag = 1;
        }
        
    }
    getchar();
    getchar();
    return 0;
}