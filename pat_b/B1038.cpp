#include <cstdio>
int main()
{
    int n, k, i;
    int scoreCnt[101] = {0};
    scanf("%d", &n);
    for (; n; n--)
    {
        scanf("%d", &i);
        scoreCnt[i] += 1;
    }
    scanf("%d", &k);
    for (int j = 0; j < k; j++)
    {
        scanf("%d", &i);
        printf("%d%c", scoreCnt[i], j == k - 1 ? '\n' : ' ');
    }
    return 0;
}