#include<cstdio>

int main()
{
    long long int a, b, c;
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t;i++)
    {
        scanf("%lld%lld%lld", &a, &b, &c);
        if(a>0&&b>0&&a+b<0)//正溢出
        {
            printf("Case #%d: true\n", i);
        }
        else if(a<0&&b<0&&a+b>0)//负溢出
        {
            printf("Case #%d: false\n", i);
        }
        
        else
        {
            if(a+b>c)
            {
                printf("Case #%d: true\n", i);
            
            }
            
            else
            {
                printf("Case #%d: false\n", i);
            }
            
        }
        
    }
    getchar();
    getchar();
    return 0;
}