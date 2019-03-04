#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct
{
    char id[9];
    int de;
    int cai;
    int rank = 5;
    int sum;
} Student;

bool cmp(Student a, Student b)
{
    if (a.rank != b.rank)
        return a.rank < b.rank;
    else if (a.sum != b.sum)
        return a.sum > b.sum;
    else if (a.de != b.de)
        return a.de > b.de;
    else
        return strcmp(a.id, b.id) >0;
}
void getRank(Student &a, int L, int H, int &M)
{
    if (a.de >= L && a.cai >= L)
    {
        if (a.de >= H && a.cai >= H)
            a.rank = 1;
        else if (a.de >= H)
            a.rank = 2;
        else if (a.de >= a.cai)
            a.rank = 3;
        else
            a.rank = 4;
        M++;
    }
}
int main()
{
    Student stuInfo[100001];
    int N, L, H, M = 0;
    scanf("%d%d%d", &N, &L, &H);
    for (int i = 0; i < N; i++)
    {
        scanf("%s%d%d", stuInfo[i].id, &stuInfo[i].de, &stuInfo[i].cai);
        stuInfo[i].sum = stuInfo[i].de + stuInfo[i].cai;
        getRank(stuInfo[i], L, H, M);
    }

    sort(stuInfo, stuInfo +N, cmp);
    printf("%d\n", M);
    for (int i = 0; i < M; i++)
    {
        printf("%s %d %d\n", stuInfo[i].id, stuInfo[i].de, stuInfo[i].cai);
    }
    getchar();
    getchar();  
    return 0;
}