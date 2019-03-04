#include <cstdio>

int main()
{
    bool allPass = true;
    bool tempPass = true;
    char input[19];
    int weight[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char check[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    int sum=0;
    int n;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", input);
        for (int j = 0; j < 17;j++)
        {
            if(input[j]>='0'&&input[j]<='9')
            {
                sum += ((input[j] - '0') * weight[j]);
            }
            else
            {
                allPass = false;
                tempPass = false;
                printf("%s\n", input);
                break;
            }
            
        }

        if(check[sum%11]!=input[17]&&tempPass)
        {
            allPass = false;
                printf("%s\n", input);
        }

        sum = 0;
        tempPass = true;
    }
    
    if(allPass)
        printf("All passed");

    return 0;
}