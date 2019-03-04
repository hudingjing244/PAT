#include<cstdio>

int main()
{
    int  c1, c2;
    scanf("%d%d", &c1, &c2);  //注意浮点数输入是lf，但是输出依然是f
    int t = c2-c1;
    if(t%100>=50)
        t = t / 100 + 1;
    
    else
    {
        t /= 100;
    }
    
    printf("%02d:%02d:%02d", t/3600, (t%3600)/60, t%60);//%2d,不足两位空格补其。%02d，不足两位用0补齐。都是最少2位右对齐。若三位就按三位输出
   
    getchar();
    getchar();
}