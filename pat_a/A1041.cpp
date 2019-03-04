#include<cstdio>

int main()
{
    int n;
    int cnt[10001] = {0};
    int idx[100000];
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        scanf("%d", idx+i);
        cnt[idx[i]]++;
    }
    bool hasWinner = false;
    for(int i = 0; i <=n; i++)
    {
        if(cnt[idx[i]]==1)
        {
            printf("%d", idx[i]);
            hasWinner = true;
            break;
        }
    }
    if(!hasWinner)
        printf("None");
    getchar();
    getchar();

    return 0;
}