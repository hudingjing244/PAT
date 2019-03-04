#include <algorithm>
#include <cstdio>
using namespace std;

struct station
{
    double dist;
    double price;
};

bool cmp(station a, station b)
{
    return a.dist < b.dist;
}

int main()
{
    double capacity, dest, perUnitDist;
    int n;
    station data[501];
    scanf("%lf%lf%lf%d", &capacity, &dest, &perUnitDist, &n);
    for (int i = 0; i < n; i++) //0 start point  n destination
    {
        scanf("%lf%lf", &data[i].price, &data[i].dist);
    }
    data[n].dist = dest;
    data[n].price = 0.0;

    sort(data, data + n + 1, cmp);
    //贪心：在我所跑的每段路上消耗的油都应该是当前能使用的最便宜的油
    //关键在于当满油距离内找不到比当前油价低的加油站时，应该在当前加油站加满油后跑到满油距离内油价最低的加油站，而不是到加恰好能到该加油站的油
    double maxRun = capacity * perUnitDist;
    double restRun = 0.0; // 到达下加油站后还剩余的油量能跑的距离
    int k = 0;
    double totalCost = 0.0;
    int now = 0;
    if(data[0].dist==0)
    {
        printf("The maximum travel distance = 0.00");
        return 0;
    }
    while (now < n)
    {
        double lowest = 9999999;
        bool hasLower = false;
        int i;
         if( data[now+1].dist - data[now].dist > maxRun)
            break;
        for ( i = now + 1; data[i].dist - data[now].dist <= maxRun; i++)
        {

            if (data[i].price <= lowest)
            {
                lowest = data[i].price;
                k = i;
                if (data[i].price <= data[now].price)
                {
                    hasLower = true;
                    break;
                }
            }
        }
       
        if (!hasLower)
        {
            totalCost += data[now].price * (maxRun - restRun) / perUnitDist;
            restRun = maxRun - (data[k].dist - data[now].dist);
        }
        else
        {
            totalCost += data[now].price * (data[k].dist - data[now].dist - restRun) / perUnitDist;
            restRun = 0;
        }
        now = k;
    }
    if (now == n)
        printf("%.2lf", totalCost);
    else
        printf("The maximum travel distance = %.2lf", maxRun + data[now].dist);

    getchar();
    getchar();
    return 0;
}