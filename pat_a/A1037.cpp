#include <algorithm>
#include <cstdio>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int nc, np;
    int ic = 0, jc, ip = 0, jp;
    int counpon[100001]={0}, product[100001]={0};

    scanf("%d", &nc);
    for (int i = 0; i < nc; i++)
    {
        scanf("%d", counpon + i);
    }
    scanf("%d", &np);
    for (int i = 0; i < np; i++)
    {
        scanf("%d", product + i);
    }
    sort(counpon, counpon + nc,cmp);
    sort(product, product + np, cmp);
    jc = nc - 1, jp = np - 1;
    int back = 0;
    while(ic<=jc&&ip<=jp)
    {
        if(counpon[ic]>0&&product[ip]>0)
        back += counpon[ic] * product[ip];
        else
            break;
        ic++, ip++;
    }
        while(ic<=jc&&ip<=jp)
    {
        if(counpon[jc]<0&&product[jp]<0)
        back += counpon[jc] * product[jp];
        else
            break;
        jc--, jp--;
    }
    printf("%d", back);
    getchar();
    getchar();
    return 0;
}