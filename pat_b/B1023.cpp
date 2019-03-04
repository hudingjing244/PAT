#include <cstdio>

int main()
{
    int cnt[10] = {0};
    int data;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &data);
        cnt[i]=data;
    }
    for (int i = 1; i < 10; i++)
    {
        if (cnt[i])
        {
            printf("%d", i);
            cnt[i]--;
            break;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        while (cnt[i]--)
        {
            printf("%d", i);
        }
    }

    getchar();
    getchar();
    return 0;
}