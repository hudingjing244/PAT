#include<cstdio>

int main()
{
    int n;
    int sumup[100001] = {0};
    int school, score;
    int winner_score = -1,winner_school=-1;

    scanf("%d",&n);
    for (int i = 0; i < n;i++)
    {
        scanf("%d%d", &school, &score);
        sumup[school] += score;
        if(winner_score<sumup[school])
        {
            winner_score = sumup[school];
            winner_school = school;
        }
    }

    printf("%d %d", winner_school, winner_score);
    return 0;
}