#include <cstdio>
typedef struct
{
    char name[6];
    int year, month, day;
} Person;
int cmp(Person a, Person b) //a生的早返回0，a生的晚返回2，同日生返回1；生的早年龄大
{
    if (a.year == b.year && a.month == b.month && a.day == b.day)
    {
        return 1;
    }
    if (a.year < b.year || (a.year == b.year && a.month < b.month) || (a.year == b.year && a.month == b.month && a.day < b.day))
    {
        return 0;
    }
    return 2;
}
int main()
{
    Person youngest, eldest, temp, lowest, highst;
    int n, count = 0;
    youngest.year = 1814, youngest.month = 9, youngest.day = 5;
    eldest.year = 2014, eldest.month = 9, eldest.day = 7;
    lowest.year = 1814, lowest.month = 9, lowest.day = 6;
    highst.year = 2014, highst.month = 9, highst.day = 6;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d/%d/%d", temp.name, &temp.year, &temp.month, &temp.day);
        if (cmp(temp, lowest) != 0 && cmp(temp, highst) != 2)//合理数据
        {
            count++;
            if (cmp(temp, eldest) == 0)//比生的最早的人还早
                eldest = temp;
            if (cmp(temp, youngest) == 2)
                youngest = temp;
        }
    }

    if (count == 0)
    {
        printf("0");
    }
    else
    {
        printf("%d %s %s", count, eldest.name, youngest.name);
    }

    return 0;
}