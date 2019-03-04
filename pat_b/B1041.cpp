#include<cstdio>

int main()
{
    int n, m;
    long long int info[1001][2] = {0};
    long long int id, prepos, realpos;

    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%lld%lld%lld", &id, &prepos, &realpos);
        info[prepos][0] = id;
        info[prepos][1] = realpos;
    }
    scanf("%d", &m);
    for (int i = 0; i < m;i++)
    {
        scanf("%lld", &prepos);
        printf("%lld %lld\n", info[prepos][0], info[prepos][1]);
    }
    getchar();
    getchar();
    return 0;

}