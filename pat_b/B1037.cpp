#include <cstdio>//改进：全部不换算成knut计算零钱，再以要求格式输出

typedef struct
{
    int g, s, n;

} money;

money abs_money(money a, money p)
{
    money e;
    if (a.n < p.n)
    {
        a.n += 29;
        if (a.s == 0)//很关键哦
        {
            a.g--;
            a.s += 17;
        }

        a.s--;
    }
    if (a.s < p.s)
    {
        a.s += 17;
        a.g--;
    }
    e.g = a.g - p.g;
    e.s = a.s - p.s;
    e.n = a.n - p.n;
    return e;
}

int main()
{

    money p, a, e; //e=a-p
    scanf("%d.%d.%d %d.%d.%d.", &p.g, &p.s, &p.n, &a.g, &a.s, &a.n);

    if (a.g > p.g || (a.g == p.g && a.s > p.s) || (a.g == p.g && a.s == p.s && a.n > p.n) || (a.g == p.g && a.s == p.s && a.n == p.n))
    {
        e = abs_money(a, p);
        printf("%d.%d.%d", e.g, e.s, e.n);
    }
    else
    {
        e = abs_money(p, a);
        printf("-%d.%d.%d", e.g, e.s, e.n);
    }

    getchar();
    getchar();

    return 0;
}