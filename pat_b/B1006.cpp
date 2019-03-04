#include<cstdio>

int main()
{
    int in;
    int temp;
    scanf("%d", &in);
    temp = in / 100;
    for (int i = 0; i < temp;i++)
    {
        printf("B");
    }
    temp = (in%100) / 10;
     for (int i = 0; i < temp;i++)
    {
        printf("S");
    }
    temp = in % 10;
     for (int i = 1; i <=temp;i++)
    {
        printf("%d",i);
    }

    getchar();
    getchar();
    return 0;
}