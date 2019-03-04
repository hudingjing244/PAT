#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

typedef struct student
{
    int id;
    int grade[4]; //a,c,m,e

} Student;
int indx;
char course[5] = "ACME";
int Rank[1000000][4] = {0}; //Rank[i][j],学号为i的学生第j门课的排名，排名不可能为0，可用于判断该学生是否存在;
bool cmp(Student a, Student b)
{
    return a.grade[indx] > b.grade[indx];
}
void bestRank(int Rank[][4], int queryID)
{
    int bestR = 2001;
    char bestC = 'A';
    for (int i = 0; i < 4; i++)
    {
        if (Rank[queryID][i] < bestR)
        {
            bestR = Rank[queryID][i];
            bestC = course[i];
        }
    }
    printf("%d %c\n", bestR, bestC);
}

int main()
{
    int n, m;
    Student stuIfo[2000];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d%d%d", &stuIfo[i].id, &stuIfo[i].grade[1], &stuIfo[i].grade[2], &stuIfo[i].grade[3]);
        stuIfo[i].grade[0] = round((stuIfo[i].grade[1] + stuIfo[i].grade[2] + stuIfo[i].grade[3]) * 1.0 / 3);
    }

    for (int i = 0; i < 4; i++)
    {
        indx = i;
        sort(stuIfo, stuIfo + n, cmp);
        Rank[stuIfo[0].id][i] = 1;
        for (int j = 1; j < n; j++)
        {
            if (stuIfo[j].grade[i] == stuIfo[j - 1].grade[i])
                Rank[stuIfo[j].id][i] = Rank[stuIfo[j - 1].id][i];
            else
            {
                Rank[stuIfo[j].id][i] = j + 1;
            }
        }
    }

    int queryID = 0;
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &queryID);
        if (Rank[queryID][0] == 0)
        {
            printf("N/A\n");
        }
        else
        {
            bestRank(Rank, queryID);
        }
    }
    getchar();
    getchar();
}