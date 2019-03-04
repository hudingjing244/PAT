#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node
{
    char name[9];
    int age;
    int netWorth;
} Billionaire;
int N, K, M, ageMin, ageMax;
Billionaire data[1000000];
bool cmp(Billionaire a, Billionaire b) //资产从高到低  年龄从小到大 姓名从小到大
{
    if (a.netWorth != b.netWorth)
        return a.netWorth > b.netWorth;
    else
    {
        if (a.age != b.age)
            return a.age < b.age;
        else
            return strcmp(a.name, b.name) < 0;
    }
}

int main()
{
    scanf("%d%d", &N, &K);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d", data[i].name, &data[i].age, &data[i].netWorth);
    }
    sort(data, data + N, cmp);

    int topn;
    for (int i = 1; i <= K; i++)
    {
        scanf("%d %d %d", &topn, &ageMin, &ageMax);
        int printCnt = 0;
        printf("Case #%d:\n", i);
        for (int j = 0; j < N && printCnt <topn; j++)
        {
            if (data[j].age <= ageMax && data[j].age >= ageMin)
            {
                printf("%s %d %d\n", data[j].name, data[j].age, data[j].netWorth);
                printCnt++;
            }
        }
        if (printCnt == 0)
            printf("None\n");
    }
    getchar();
    getchar();
    return 0;
}