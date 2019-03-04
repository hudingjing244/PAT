#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int n = 0, dist[100000] = {0}, m = 0, a = 0, b = 0;
    int sum = 0, cw = 0;//一圈总长，i到j的顺时针总长
    scanf("%d", &n);
    for (int i = 1; i <= n;i++)
    {
        scanf("%d", dist + i);
        sum += dist[i];

    }
    scanf("%d", &m);
     
    
        for (int i = 0; i < m; i++)
        {
            cw = 0;
            scanf("%d%d", &a, &b);
            if (a > b)
                swap(a, b);
            for (int j = a; j < b; j++)
            {
                cw += dist[j];
            }
            printf("%d\n", min(cw, sum-cw));
        }
    getchar();
    getchar();
    return 0;
}