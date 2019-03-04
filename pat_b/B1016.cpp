#include <cstdio>

int main()
{
    long long a, b, da, db, pa, pb;
    scanf("%lld%lld%lld%lld", &a, &da, &b, &db);
    pa = 0, pb = 0;
    while(a)
    {
        if(a%10==da)
            pa = (10 * pa + da);
        a /= 10;
    }
    while(b)
    {
        if(b%10==db)
            pb = (10 * pb + db);
        b /= 10;
    }
    printf("%lld\n", pa+pb);
    getchar();
    getchar();
    return 0;
}