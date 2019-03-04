#include<cstdio>
char shape(int a)
{
    if(a<=13)
        return 'S';
    else if(a<=26)
        return 'H';
    else if(a<=39)
        return 'C';
    else if(a<=52)
        return 'D';
    else
    {
        return 'J';
    }
}
int num(int a )
{
    
    if(a%13==0)
    {
        return 13;
    }
    
    else
    {
        return a % 13;
    }
    
}
// num()函数可以用lambda表达式  start[i]%13==0?13:start[i]%13
int main()
{
    int start[55] = {0};
    int end[55] = {0};
    int order[55] = {0};
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= 54; i++)
        scanf("%d", order + i);

    for (int i = 1; i <= 54; i++)
    {
        start[i] = i;
    }
  //置换
    while(n--)
    {
        for (int i = 1; i <= 54; i++)
        {
            end[order[i]] = start[i];
        }
        for (int i = 1; i <= 54; i++)
            start[i] = end[i];
    }
//输出结果
    for (int i = 1; i <= 53;i++)
        printf("%c%d ", shape(start[i]), num(start[i]));
    
    printf("%c%d", shape(start[54]), num(start[54]));

    
    return 0;

}