#include <algorithm>
#include <cstdio>
using namespace std;

typedef struct node
{
    int id;
    int entranceGrade;
    int interviewGrade;
    double finalGrade;
    int choices[5];
    int rank;
    int admitted = 101; //被谁录取
} Applicant;
 Applicant data[40001];
int n, m, k;
int schoolQuota[100];

bool cmprank(Applicant a, Applicant b)
{
    return a.finalGrade != b.finalGrade ? a.finalGrade > b.finalGrade : a.entranceGrade > b.entranceGrade;
}

bool cmpout(Applicant a, Applicant b)
{
    return a.admitted != b.admitted ? a.admitted < b.admitted : a.id < b.id;
}

int main()
{
   
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i++)
    {
        scanf("%d", schoolQuota + i);
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &data[i].entranceGrade, &data[i].interviewGrade);
        for (int j = 0; j < k; j++)
            scanf("%d", &data[i].choices[j]);
        data[i].id = i;
        data[i].finalGrade = (data[i].entranceGrade + data[i].interviewGrade) / 2.0;
    }
    sort(data, data + n, cmprank);
    data[0].rank = 1;
    for (int i = 1; i < n; i++)
    {
        if (data[i].finalGrade == data[i - 1].finalGrade && data[i].entranceGrade == data[i - 1].entranceGrade)
            data[i].rank = data[i - 1].rank;
        else
            data[i].rank = i + 1;
    }
    int lastAdmitRank[100] = {0}; //当某校配额分配完时记录最后一个被录取学生的的排名
    int schoolID;
    int admitCnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            schoolID = data[i].choices[j];
            if (schoolQuota[schoolID] > 0)
            {
                schoolQuota[schoolID]--;
                data[i].admitted = schoolID;
                admitCnt++;
                if (schoolQuota[schoolID] == 0)
                    lastAdmitRank[schoolID] = data[i].rank;
                break; //录取了就不看下一志愿了
            }
            else
            {
                if (lastAdmitRank[schoolID] == data[i].rank)
                {
                    data[i].admitted = schoolID;
                    admitCnt++; 
                    break;
                }

               
            }
        }
    }
    sort(data, data + n, cmpout);

    int nowSchool = 0;
    for (int i = 0; i < admitCnt; i++)
    {
        if (data[i].admitted != nowSchool)
        {
            while (data[i].admitted != nowSchool)
            {
                printf("\n");
                nowSchool++;
            }
        }

        if (data[i + 1].admitted == nowSchool)
            printf("%d ", data[i].id);
        else
            printf("%d", data[i].id);
    }

    while (m> nowSchool)//之所以不是m-1是因为上面代码的换行符是根据下一行数据判断的，也即是末尾一定得多加一个换行符
    {
        printf("\n");
        nowSchool++;
    }
    getchar();
    getchar();

    return 0;
}