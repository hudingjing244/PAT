#include <cstdio>

int main()
{
    int hasBeads[128]={0};
    char c;
    int extra=0, cnt1 = 0, cnt2=0,missing = 0;
    while((c=getchar())!='\n')
    {
        hasBeads[c]++;
        cnt1++;
    }
        while((c=getchar())!='\n')
    {
       if(hasBeads[c]>0)
       {
           cnt2++;
           hasBeads[c]--;
       }
       else
           missing++;
    }
    printf("%s ", missing ? "No" : "Yes");
    printf("%d", missing ? missing : cnt1 - cnt2);
    return 0;
}