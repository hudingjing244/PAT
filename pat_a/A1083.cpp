#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct node
{
    char name[11];
    char id[11];
    bool exist=false;
} STU;

int main()
{
    int n, printCnt = 0;
    int grade1, grade2;
    char name[11];
    char id[11];
    int grade = false;
    STU stuInfo[101];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d", name, id, &grade);
        strcpy(stuInfo[grade].name, name);
        strcpy(stuInfo[grade].id, id);
        stuInfo[grade].exist = true;
    }
    scanf("%d%d", &grade1, &grade2);
    for (; grade1 <= grade2; grade2--)
    {
        if (stuInfo[grade2].exist)
        {
            printCnt++;
            printf("%s %s\n", stuInfo[grade2].name, stuInfo[grade2].id);
        }
    }
    if (printCnt == 0)
        printf("NONE");

    getchar();
    getchar();
    return 0;
}