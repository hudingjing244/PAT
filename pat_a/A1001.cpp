#include <cstdio>

int main()
{
    int a, b, sum;
    int sumdigits[8];
    int count = 0;

    scanf("%d%d", &a, &b);
    sum = a + b;

    if (sum < 0)
        putchar('-');


    sum = sum < 0 ? ((-1) * sum) : sum;

    do
    {
        sumdigits[++count] = sum % 10;
        sum /= 10;
    } while (sum);



    for (; count > 0; count--)
    {
       
        printf("%d", sumdigits[count]);
         if ((count-1)% 3 == 0&&count>1)
            putchar(',');
    }

    getchar();
    getchar();
    return 0;
}