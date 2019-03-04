#include <cstdio>

int main()
{
    int n;
    int covered[101] = {0}; //0输入数据中没出现，1表示出现了，2表示被覆盖  
    int temp;

    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &temp);
        if (covered[temp] != 2)
            covered[temp] = 1;
        while (temp != 1)
        {
            if (temp % 2 == 0)
            {
                temp /= 2;
                if(temp<=100)     //(99*3-1)/2=149  (149*3-1)/2=224甚至有的数中间结果更大，会数组越界，但又没必要记录，所以判断一下
                covered[temp] = 2;
            }
            else
            {
                temp = (3 * temp + 1) / 2;
                 if(temp<=100)
                covered[temp] = 2;
            }
        }
    }
    bool printed = false;
    for (int i = 100; i > 0; i--)
    {
        if (covered[i] == 1)
        {
            
            printf("%c%d",printed?' ':'\0', i);
            printed = true;
            
        }
    }

    getchar();
    getchar();

    return 0;
}