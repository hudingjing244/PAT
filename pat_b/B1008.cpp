#include <cstdio>

void reverse(int arr[],int low, int high)
{
    int temp;
    while(low<high)
    {
        temp = arr[low];
        arr[low] = arr[high];
        arr[high] = temp;
        low++;
        high--;
    }
}
int main()
{
    int n, m;
    int arr[100]; //n<=100;
    scanf("%d%d", &n, &m);
    m = m % n;//注意题目的坑，没给M的范围
    for (int i = 0; i < n;i++)
    {
        scanf("%d", arr+i);
    }

    reverse(arr, 0,n-m - 1);
    reverse(arr, n-m, n - 1);
    reverse(arr, 0, n - 1);
    for (int i = 0; i < n-1;i++)
    {
        printf("%d ", arr[i]);
    }
    printf("%d", arr[n - 1]);

    getchar();
    getchar();
}