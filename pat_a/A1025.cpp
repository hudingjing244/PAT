#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node
{
    char id[14];//用long long存储的时候同样的算法 最后一个测试点过不去，不知道为什么 保险起见 这种int存不下的大数还是字符串吧
    int score;
    int locID;
    int locRank;
} Testee;

bool cmp(Testee a, Testee b)
{
    return a.score == b.score ? strcmp(a.id,b.id)<0 : a.score > b.score;
}

int main()
{
    Testee testees[30000];
    int n, k;
    int total = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &k);
        for (int j = 0; j < k; j++)
        {
            scanf("%s%d", testees[total].id, &testees[total].score);
            testees[total].locID = i;
            total++;
        }
        sort(testees + total - k, testees + total, cmp);
        testees[total - k].locRank = 1;
        for (int j = total - k + 1; j < total; j++)
        {
            testees[j].locRank = testees[j].score == testees[j - 1].score ? testees[j - 1].locRank : j - (total - k) + 1;
        }
    }
    sort(testees, testees + total, cmp);
    int finalRank = 1;
    printf("%d\n", total);
    for (int i = 0; i < total; i++)
    {
        if (i > 0 && testees[i].score != testees[i - 1].score)
            finalRank = i + 1;
        printf("%s %d %d %d\n", testees[i].id, finalRank, testees[i].locID, testees[i].locRank);
    }
    getchar();
    getchar();
    return 0;
}