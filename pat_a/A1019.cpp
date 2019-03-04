#include <cstdio>

int main()
{
    int n, b;
    int ans[35];
    int len = 0; //len指向有效数据的下一个位置；

    scanf("%d %d", &n, &b);

    if (n == 0)
    {
        printf("No\n0");
    }
    else
    {
        while (n)//do...while不需要特判0
        {
            ans[len++] = n % b;
            n /= b;
        }

        int i = 0;
        int j = len - 1;
        for (; i < j; i++, j--)
        {
            if (ans[i] != ans[j])
                break;
        }

        if (i == j)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }


        for (i = len - 1; i >0; i--)
        {
            printf("%d ", ans[i]);
        }
        printf("%d", ans[0]);
    }

    getchar();
    getchar();

    return 0;
}