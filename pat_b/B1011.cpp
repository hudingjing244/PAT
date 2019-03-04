#include <cstdio>


int main()
{
    long long int T, A,B,C;
    scanf("%lld",&T);
    for (int i = 1; i <= T;i++)
    {
        scanf("%lld%lld%lld",&A,&B,&C);
        if(A+B>C)
            printf("Case #%d: true\n", i);
        else
             printf("Case #%d: false\n", i);
    }
    return 0;
}