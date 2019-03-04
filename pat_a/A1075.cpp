#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct node
{
    int id_score[6] = {0, -2, -2, -2, -2, -2}; //0号位是id
    int totalScore = 0;
    int perfectPassCnt = 0;
    bool print = false;
} Testee;
int fullScore[6] = {0};
bool cmp(Testee a, Testee b)
{
    if (a.totalScore != b.totalScore)
        return a.totalScore > b.totalScore;
    else if (a.perfectPassCnt != b.perfectPassCnt)
        return a.perfectPassCnt > b.perfectPassCnt;
    else
        return a.id_score[0] < b.id_score[0];
}

int main()
{
    int id, cId, score;
    int n, k, m;
    Testee data[10001];
    scanf("%d%d%d", &n, &k, &m);
    for (int i = 1; i <= k; i++)
        scanf("%d", fullScore + i);
    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &id, &cId, &score);
        if (score > data[id].id_score[cId])
        {
            data[id].id_score[cId] = score;
            data[id].id_score[0] = id;
            if (score == fullScore[cId])
                data[id].perfectPassCnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (data[i].id_score[j] >= 0)
            {
                data[i].totalScore += data[i].id_score[j];
                data[i].print = true;
            }
        }
    }
    sort(data + 1, data + n + 1, cmp); //id从1开始，所以存的数据在1-n

    int rank = 1;
    for (int i = 1; i <= n; i++)
    {
        if(data[i].totalScore!=data[i-1].totalScore&&i>1)
            rank = i;
        if(data[i].print)
        {
            printf("%d %05d %d",rank,data[i].id_score[0],data[i].totalScore);
            for (int j = 1; j <= k; j++)
            {
                if(data[i].id_score[j]>=0)
                    printf(" %d",data[i].id_score[j]);
                else if(data[i].id_score[j]==-1)
                    printf(" 0");
                else
                    printf(" -");
            }
            printf("\n");
        }
    }

    return 0;
}