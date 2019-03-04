#include <cstdio>
//改进：多项式B的输入和C的求解不用分成两个循环来做，完全可以输入B的时候同时算C
//输出要求最后无空格，可以每个输出前面加上空格，这样就不需要kc来判断最后一个元素了
int main()
{
    double A[1001] = {0.0}, B[1001] = {0.0}, C[2001] = {0.0};//注意C的大小
    int ka, kb, kc = 0;
    int ex;
    double coef;
    scanf("%d", &ka);
    for (int i = 0; i < ka; i++)
    {
        scanf("%d%lf", &ex, &coef);
        A[ex] = coef;
    }

    scanf("%d", &kb);
    for (int i = 0; i < kb; i++)
    {
        scanf("%d%lf", &ex, &coef);
        B[ex] = coef;
    }

    for (int i = 0; i < 1001; i++)
    {
        for (int j = 0; j < 1001; j++)
        {
            if (A[i] != 0.0 && B[j] != 0.0)
            {
                C[i + j] += (A[i] * B[j]);
            }
        }
    }

    for (int i = 0; i <2001; i++)
    {
        if (C[i] != 0.0)
            kc++;
    }

    if (kc == 0)
        printf("0");
    else
    {
        printf("%d ", kc);
    }

    int k;
    for (k = 2000; k >= 0 && kc > 1; k--)
    {
        if (C[k] != 0.0)
        {
            kc--;
            printf("%d %.1lf ", k, C[k]);
        }
    }

    for (int i = k; k >= 0; k--)
    {
        if (C[k] != 0.0)
        {

            printf("%d %.1lf", k, C[k]);
        }
    }
    getchar();
    getchar();
    return 0;
}