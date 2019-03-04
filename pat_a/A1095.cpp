#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>
#include <vector>
using namespace std;

struct info
{
    char id[8];
    int h, m, s;
    int time;
    char status[4];
};
int n, k;
bool cmpIdAanTime(info a, info b)
{
    return strcmp(a.id, b.id) != 0 ? strcmp(a.id, b.id) < 0 : a.time < b.time;
}
bool cmpTime(info a, info b)
{
    return a.time < b.time;
}

int main()
{
    vector<info> inputData;
    vector<info> validData;
    info temp;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d:%d:%d %s", temp.id, &temp.h, &temp.m, &temp.s, temp.status);
        temp.time = temp.h * 3600 + temp.m * 60 + temp.s;
        inputData.push_back(temp);
    }
    sort(inputData.begin(), inputData.end(), cmpIdAanTime);
    map<string, int> totalPark;
    int maxTotalPark = -1;
    auto in = inputData.begin();
    auto out = inputData.begin() + 1;
    for (; out != inputData.end(); in++, out++)
    {
        if (strcmp((*in).status, "in") == 0 && strcmp((*out).status, "out") == 0 && strcmp((*in).id, (*out).id) == 0)
        {
            validData.push_back(*in);
            validData.push_back(*out);
            if (totalPark[(*in).id] == 0)
                totalPark[(*in).id] = 0;
            totalPark[(*in).id] += ((*out).time - (*in).time);
            if (maxTotalPark < totalPark[(*in).id])
                maxTotalPark = totalPark[(*in).id];
        }
    }

    sort(validData.begin(), validData.end(), cmpTime);
    int query[4];
    //以下两个变量设为查询的外部变量是因为查询是按时间递增来的，前面查过的就不必重复，否则超时
    auto it = validData.begin();
    int now = 0;
    for (int i = 0; i < k; i++)
    {
        scanf("%d:%d:%d", query, query + 1, query + 2);
        query[3] = query[0] * 3600 + query[1] * 60 + query[2];
        for (; it != validData.end() && (*it).time <= query[3]; it++)
        {
            if (strcmp((*it).status, "in") == 0)
                now++;
            else
                now--;
        }
        printf("%d\n", now);
    }

    for (auto it = totalPark.begin(); it != totalPark.end(); it++)
    {
        if (it->second == maxTotalPark)
            printf("%s ", (it->first).c_str());
    }
    printf("%02d:%02d:%02d", maxTotalPark / 3600, (maxTotalPark % 3600) / 60, maxTotalPark % 60);

    getchar();
    getchar();
    return 0;
}
