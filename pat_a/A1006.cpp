#include <cstdio>
typedef struct
{
    char id[16];
    int time[2][3]; //0-in,1-out;0-hh,1-mm,2-ss
} Record;

int cmp(Record a, Record b,int i) //a早返回0，晚返回2，同时返回1；
{
    if (a.time[i][0] == b.time[i][0] && a.time[i][1] == b.time[i][1] && a.time[i][2] == b.time[i][2])
        return 1;
    if (a.time[i][0] < b.time[i][0] || (a.time[i][0] == b.time[i][0] && a.time[i][1] < b.time[i][1]) || (a.time[i][0] == b.time[i][0] && a.time[i][1] == b.time[i][1] && a.time[i][2] < b.time[i][2]))
        return 0;
    return 2;
}
int main()
{
    int n;
    Record first_in, last_out, temp;
    first_in.time[0][0] = 24, first_in.time[0][1] = 0, first_in.time[0][2] = 0;
    last_out.time[1][0] = -1, last_out.time[1][1] = 59, last_out.time[1][2] = 59;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %d:%d:%d", temp.id, &temp.time[0][0], &temp.time[0][1], &temp.time[0][2], &temp.time[1][0], &temp.time[1][1], &temp.time[1][2]);

        if (cmp(temp, first_in, 0) == 0)
            first_in = temp;
        if (cmp(last_out, temp, 1) == 0)
            last_out = temp;
    }

    printf("%s %s", first_in.id, last_out.id);
    return 0;
}