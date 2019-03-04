#include <cstdio>

int main()
{
    int total[1001] = {0};
    int n, team, member, score;
    scanf("%d", &n);
    int topScore = 0, topTeam;
    for(int  i = 0; i < n; i++)
    {
        scanf("%d-%d %d", &team, &member, &score);
        total[team]+=score;
        if(topScore<total[team])
            {
                topScore = total[team];
                topTeam = team;
            }
    }
    printf("%d %d", topTeam, topScore);
    getchar();
    getchar();

    return 0;
}