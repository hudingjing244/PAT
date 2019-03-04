#include<cstdio>
//下次试着用map<char,int>
char max(int C,int J, int B)
{
    if(B>=C&&B>=J)
        return 'B';
    if(C>B&&C>=J)
        return 'C';
    return 'J';
}
int main()
{
    int n;
    char a, b;
    int C1=0, J1=0, B1=0;
    int C2=0, J2=0, B2=0;
    int asucc=0,bsucc=0, equal=0;


    scanf("%d", &n);
    while(n--)
    {
        getchar();//scanf %c 会将空格符和换行符均当成输入字符
        scanf("%c %c", &a, &b);
        if(a==b)//平局
        {
            equal++;
        }
        else if(a=='C')
        {
            if(b=='J')
            {
                asucc++;
                C1++;
            }
            else
            {
                bsucc++;
                B2++;
            }
        }
        else if(a=='B')
        {
            if(b=='J')
            {
                bsucc++;
                J2++;
            }
            else
            {
                asucc++;
                B1++;
            }
        }
        else if(a=='J')
        {
            if(b=='B')
            {
                asucc++;
                J1++;
            }
            else
            {
                bsucc++;
                C2++;
            }
        }
    }

    printf("%d %d %d\n", asucc, equal, bsucc);
    printf("%d %d %d\n", bsucc, equal, asucc);

    printf("%c %c", max(C1, J1, B1), max(C2, J2, B2));

    getchar();
    getchar();
}