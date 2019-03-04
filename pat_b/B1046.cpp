#include<cstdio>

int main()
{
    int N;
    int a1, a2, b1, b2,sum;//每轮情况
    int count1=0, count2=0;//甲乙喝酒次数，也就是输的次数
    scanf("%d", &N);
    for (int i = 0; i < N;i++)
    {
        scanf("%d%d%d%d", &a1, &a2, &b1, &b2);
        sum = a1 + b1;
        if(a2!=sum&&b2==sum)//甲喝
            count1++;
        if(b2!=sum&&a2==sum)
            count2++;
    }
    printf("%d %d", count1, count2);
    getchar();
    getchar();

}