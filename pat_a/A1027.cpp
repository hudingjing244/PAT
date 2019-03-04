#include <cstdio>

int main()
{
    int ans[6];
    int rgb[3];

    scanf("%d%d%d", rgb, rgb + 1, rgb + 2);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j >= 0; j--)
        {
            ans[2 * i + j] = rgb[i] % 13;
            rgb[i] /= 13;
        }
    }
    printf("#");
    for (int i = 0; i < 6; i++)
    {
        if (ans[i] < 10)
            printf("%d", ans[i]);
        else if (ans[i] == 10)
            printf("A");
        else if (ans[i] == 11)
            printf("B");
        else if (ans[i] == 12)
            printf("C");
    }

    getchar();
    getchar();

    return 0;
}