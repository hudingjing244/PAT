#include <algorithm>
#include <cstdio>
using namespace std;
const int maxsize = 100000;

int main()
{
    long long  data[maxsize];
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", data + i);
    }
    sort(data, data + n);

    int cntMax = 0;
    int minIndx = 0;
    int maxIndx = n-1;
    long long mp = data[minIndx] * p;
    while (true)
    {
        if(data[maxIndx ] <= mp)
            break;
        maxIndx--;
    }

    while (cntMax < n - minIndx)
    {
        mp = data[minIndx] * p;

        while (maxIndx < n - 1)
        {
            if (data[maxIndx + 1] <= mp)
            {
                maxIndx++;
            }
            else
                break;
        }

        cntMax = maxIndx - minIndx + 1 > cntMax ? maxIndx - minIndx + 1 : cntMax;

        minIndx++;
    }
    printf("%d", cntMax);
    getchar();
    getchar();
    return 0;
}