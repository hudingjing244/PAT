#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

typedef struct _record
{
    char name[21];
    int mon, day, hour, minute;
    char status[9];
} Record;
int toll[24];

bool cmp(Record a, Record b)
{
    if (strcmp(a.name, b.name) != 0)
        return strcmp(a.name, b.name) < 0;
    else if (a.day != b.day)
        return a.day < b.day;
    else if (a.hour != b.hour)
        return a.hour < b.hour;
    else
        return a.minute < b.minute;
}
int dayCharge = 0;
int duration = 0;
int charge(Record on, Record off, int &duration) //cents
{
    int amount = 0;
    duration = 0;
    if (on.day == off.day)
    {
        if (on.hour == off.hour)
        {
            amount = amount + (off.minute - on.minute) * toll[on.hour];
            duration = duration + (off.minute - on.minute);
        }
        else
        {
            amount = amount + (60 - on.minute) * toll[on.hour] + off.minute * toll[off.hour];
            duration = duration + (60 - on.minute) + off.minute;
            for (int i = on.hour + 1; i < off.hour; i++)
            {
                amount += (60 * toll[i]);
                duration += 60;
            }
        }
    }
    else
    {
        amount = dayCharge * (off.day - 1 - on.day);
        duration = (off.day - 1 - on.day) * 24 * 60;

        for (int i = 0; i < off.hour; i++)
        {
            amount = amount + toll[i] * 60;
            duration += 60;
        }
        amount = amount + toll[off.hour] * off.minute;
        duration += off.minute;

        for (int i = on.hour + 1; i < 24; i++)
        {
            amount = amount + toll[i] * 60;
            duration += 60;
        }
        amount = amount + toll[on.hour] * (60 - on.minute);
        duration += (60 - on.minute);
    }

    return amount;
}
int main()
{
    Record recInfo[1000];
    int N;
    for (int i = 0; i < 24; i++)
    {
        scanf("%d", toll + i);
        dayCharge += (60 * toll[i]);
    }
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        getchar();
        scanf("%s %d:%d:%d:%d %s", recInfo[i].name, &recInfo[i].mon, &recInfo[i].day, &recInfo[i].hour, &recInfo[i].minute, recInfo[i].status);
    }
    sort(recInfo, recInfo + N, cmp);

    int on, off;
    bool newGuy = true;
    bool hasValid = false; //存在合法数据
    double totalCharge = 0.0;
    double tempCharge = 0.0;
    //每个账单打印三部分：
    //第一部分打印条件：是新用户，存在匹配的正确数据
    //第二部分打印条件：存在匹配的正确数据
    //第三部分打印条件: 切换用户或者达到末尾的同时满足上一用户存在匹配的正确数据

    //注释部分死活过不了第一个测试点
    /*   for (on = 0, off = 1; off < N; on++, off++)
    {
        if (strcmp(recInfo[on].name, recInfo[off].name) == 0 && strcmp(recInfo[on].status, "on-line") == 0 && strcmp(recInfo[off].status, "off-line") == 0)
        {
            if (newGuy)
            {               
                printf("%s %02d\n", recInfo[on].name, recInfo[on].mon);
            }
            tempCharge = (charge(recInfo[on], recInfo[off], duration)) / 100.0;
            totalCharge += tempCharge;
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", recInfo[on].day, recInfo[on].hour, recInfo[on].minute, recInfo[off].day, recInfo[off].hour, recInfo[off].minute, duration, tempCharge);
            newGuy = false;
        }
        else if (strcmp(recInfo[on].name, recInfo[off].name) != 0 || off == N - 1)
        {
            if ((newGuy==false||off==N-1)&&totalCharge!=0.0)
                printf("Total amount: $%.2lf\n", totalCharge);
            newGuy = true;
            totalCharge = 0.0;
        }
    }
*/

    Record validRecord[1000];
    int validCnt = 0;
    for (on = 0, off = 1; off < N; on++, off++)
    {
        if (strcmp(recInfo[on].name, recInfo[off].name) == 0 && strcmp(recInfo[on].status, "on-line") == 0 && strcmp(recInfo[off].status, "off-line") == 0)
        {
            validRecord[validCnt++] = recInfo[on];
            validRecord[validCnt++] = recInfo[off];
        }
    }

    for (on = 0, off = 1; off < validCnt; on += 2, off += 2)
    {

        if (on == 0 || strcmp(validRecord[on].name, validRecord[on - 1].name) != 0)
        {
            printf("%s %02d\n", validRecord[on].name, validRecord[on].mon);
        }
        tempCharge = (charge(validRecord[on], validRecord[off], duration)) / 100.0;
        totalCharge += tempCharge;
        printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2lf\n", validRecord[on].day, validRecord[on].hour, validRecord[on].minute, validRecord[off].day, validRecord[off].hour, validRecord[off].minute, duration, tempCharge);

        if (off == validCnt - 1 || strcmp(validRecord[off].name, validRecord[off + 1].name) != 0)
        {

            printf("Total amount: $%.2lf\n", totalCharge);

            totalCharge = 0.0;
        }
    }

    getchar();
    getchar();
    return 0;
}