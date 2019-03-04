#include <cstdio>

int main()
{
    int a, b, d;
    int sum;
    int ans[33];
    int len = 0;
    scanf("%d%d%d", &a, &b, &d);
    sum = a + b;

    if (sum == 0)
    {
        printf("0");
    }
    else
    {
        while (sum)
        {
            ans[len++] = sum % d;
            sum /= d;
        }
        for (int i = len - 1; i >= 0; i--)
        {
            printf("%d", ans[i]);
        }
    }

    getchar();
    getchar();

    return 0;
}