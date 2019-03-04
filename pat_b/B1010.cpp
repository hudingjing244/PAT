#include<cstdio>

int main()
{
    int poly[2000][2] = {{0}};
    int n = 0;
    while(scanf("%d%d",&(poly[n][0]),&(poly[n][1]))!=EOF)
    {
        n++;

    }

    for (int i = 0; i < n;i++)
    {
        poly[i][0] = poly[i][0] * poly[i][1];
        if(poly[i][1]!=0)
        {
         poly[i][1] = poly[i][1] - 1;
        }
        
        else
        {
            n--;//0项不输出
        }
        

    }
    if(n>0)
    {
    for (int i = 0; i < n-1;i++)
    {
        printf("%d %d ", poly[i][0], poly[i][1]);
    }
    printf("%d %d", poly[n-1][0], poly[n-1][1]);
    }
    
    else
    {
        printf("0 0");//0多项式特殊输出
    }
    
    getchar();
    getchar();
    return 0;
    
}