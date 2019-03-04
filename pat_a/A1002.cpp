#include<cstdio>

int main()
{
    int ka, kb,kc=0;
    int exp;
    double coef;
    double A[1001] = {0.0};//double类型初始化和判断条件给的如果是常数，加个.0 以免乱七八糟的错误
    double B[1001] = {0.0};
    double C[1001] = {0.0};
    scanf("%d", &ka);
    for (int i = 0; i < ka;i++)
    {
        scanf("%d%lf", &exp, &coef);
        A[exp] = coef;
    }

    scanf("%d", &kb);
    for (int i = 0; i < kb;i++)//别while(kb--),那样怎么算kc初值？
    {
        scanf("%d%lf", &exp, &coef);
        B[exp] = coef;
    }

    kc = ka + kb;
    for (int i = 0; i <= 1000;i++)
    {
        C[i] = A[i] + B[i];
        if(A[i]!=0.0&&B[i]!=0.0)//相同幂次A B都有非零项时
        {
            if(C[i]==0.0)//如果A B系数为相反数，完全抵消
            {
                kc -= 2;
            }
            else//否则只减掉一个多算的
            {
                kc--;
            }
            
        }
        
    }


    int j=1000;
    if(kc==0)//这个判断条件是以防kc为0时，输出结果末尾多了空格
        printf("0");
    else
    {        
        printf("%d ", kc);
    } 
    for ( j = 1000; j >= 0 && kc > 1;j--)//多项式是降幂顺序书写输出
    {
        if(C[j]!=0.0)
         {
             printf("%d %.1lf ", j, C[j]);
             kc--;
         }   
    }
    for (int i = j; i >= 0;i--)
    {
        if(C[i]!=0.0)
            printf("%d %.1lf", i, C[i]);
    }
    getchar();
    getchar();
    return 0;
}