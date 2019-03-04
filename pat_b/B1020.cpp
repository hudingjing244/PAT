#include <algorithm>
#include <cstdio>
using namespace std;

struct node
{
    double storage;//随后一行给出 N 个正数表示每种月饼的库存量，没说是整数
    double totalPrice;
    double singlePrice;
};
bool cmp(node a, node b)
{
    return a.singlePrice > b.singlePrice;
}

int main()
{
    node data[1000];
    int n, demand;
    scanf("%d%d", &n, &demand);
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &data[i].storage);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%lf", &data[i].totalPrice);
        data[i].singlePrice = data[i].totalPrice * 1.0 / data[i].storage;
    }

    sort(data, data + n, cmp);
    double maxProfit = 0.0;
    for (int i = 0; i < n && demand; i++)
    {
        if (demand >= data[i].storage )
        {
            maxProfit += data[i].totalPrice;
            demand -= data[i].storage;
        }
        else
        {
            maxProfit += (data[i].singlePrice * demand);
            demand = 0;
        }
    }
    printf("%.2lf", maxProfit);
    getchar();
    getchar();
    return 0;
}