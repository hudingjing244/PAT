#include<cstdio>
//教训：变量还是初始化一下吧，初始化了全部通过了，没初始化部分测试点错误，我也不知道为什么
int main()
{
    int n, a[1000];
    int a1=0, a2=0, a3=0, count4=0,max=0;
    int f1=0, f2=0, f3=0, f4=0, f5=0;
    double a4=0.0;
    int flag = 1;
    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d", a + i);
    }
    for (int i = 0; i < n;i++)
    {
        if(a[i]%5==0&&a[i]%2==0)
        {
            a1 += a[i];
            f1 = 1;
        }
        


        if(a[i]%5==1)
        {
            if(flag)
            {
                a2 += a[i];
                flag = 0;
            }
            
            else
            {
                a2 -= a[i];
                flag = 1;
            }
            f2 = 1;
        }

        if(a[i]%5==2)
        {
            a3++;
            f3 = 1;
        }
        
        if(a[i]%5==3)
        {
            count4++;
            a4 += a[i];
            f4 = 1;
        }

        if(a[i]%5==4)
        {
                if(a[i]>max)
                    max = a[i];
       
            f5 = 1;
        }
    }

    a4 /= count4;

    if(f1)
        printf("%d ", a1);
    
    else
    {
        printf("N ");
    }

    if(f2)
        printf("%d ", a2);
    
    else
    {
        printf("N ");
    }
    
    if(f3)
        printf("%d ", a3);
    
    else
    {
        printf("N ");
    }

    if(f4)
        printf("%.1f ", a4);
    
    else
    {
        printf("N ");
    }
    if(f5)
        printf("%d", max);
    
    else
    {
        printf("N");
    }

    getchar();
    getchar();
}