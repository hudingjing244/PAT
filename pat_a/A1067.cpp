#include <cstdio>
const int maxSize = 100000;
int cnt = 0;
int n;
void swap(int i, int j, int data[], int indx[])
{
    indx[data[i]] = j;
    indx[data[j]] = i;
    int temp = data[i];
    data[i] = data[j];
    data[j] = temp;
    cnt++;
}
int main()
{
    int data[maxSize];

    int indx[maxSize];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", data + i);
        indx[data[i]] = i;
    }
    int i = 1;//没回到自身位置的数中索引最小的那个数的索引，如果每次都从1开始遍历，会超时
    while (true)
    {
        if(indx[0]!=0)
        swap(indx[0], indx[indx[0]], data, indx);
        else
        {
           bool ordered = true;
            for (; i < n; i++)
            {
                if (i != data[i])
                {
                    swap(i,0, data, indx);
                    ordered = false;
                    break;
                }
            }
            if (ordered)
                break;
            
        }
        
    } 

    printf("%d", cnt);
    getchar();
    getchar();
    return 0;
}