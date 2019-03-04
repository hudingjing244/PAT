#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

typedef struct node 
{
    int id;
    char name[9];
    int score;
} STUDENT;

int N,C;
bool cmp(STUDENT a,STUDENT b)
{
    if(C==1)
        return a.id < b.id;
    else if(C==2)
    {
        return strcmp(a.name, b.name) != 0 ?  strcmp(a.name, b.name) < 0:a.id<b.id;
    }
    else
    {
        return a.score != b.score ? a.score < b.score : a.id < b.id;
    }
}
int main()
{
    STUDENT stuInfo[100000];
    scanf("%d%d", &N, &C);
    for (int i = 0; i < N;i++)
    {
        scanf("%d %s %d", &stuInfo[i].id, stuInfo[i].name, &stuInfo[i].score);
    }
    sort(stuInfo, stuInfo + N, cmp);
    for (int i = 0; i < N;i++)
    {
        printf("%06d %s %d\n", stuInfo[i].id, stuInfo[i].name, stuInfo[i].score);
    }

    getchar();
    getchar();
    return 0;
}