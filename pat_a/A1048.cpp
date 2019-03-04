#include <cstdio>

int main()
{
    int faceValue[501] = {0};
    int n, m, indx;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &indx);
        faceValue[indx]++;
    }
    int start = m > 500 ? m - 500 : 1;
    int end = m % 2 ? m / 2 + 1 : m / 2;
    for (int i =start ; i <= end; i++)
    {
        if (i == m - i ? faceValue[i] >= 2 : (faceValue[i] >= 1 && faceValue[m - i] >= 1))
        {
            printf("%d %d", i, m - i);
            getchar();
            getchar();
            return 0;
        }
    }
    printf("No Solution");
    getchar();
    getchar();
    return 0;
}