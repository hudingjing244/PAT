#include<cstdio>

typedef struct 
{
    char name[11];
    char id[11];
    char gender;
    int score;
} Student;

int main()
{
    Student bestGirl, worstBoy, temp;
    int n;
    bool existGirl = false, existBoy = false;//可以不要，最后判断score是否为-1,101即可

    bestGirl.score = -1;
    worstBoy.score = 101;

    scanf("%d", &n);
    for (int i = 0; i < n;i++)
    {
        scanf("%s %c %s %d", temp.name, &temp.gender, temp.id, &temp.score);
        if(temp.gender=='M'&&temp.score<worstBoy.score)
        {
            existBoy = true;
            worstBoy = temp;
        }
        if(temp.gender=='F'&&temp.score>bestGirl.score)
        {
            existGirl = true;
            bestGirl = temp;
        }

    }
    if(existGirl)
        printf("%s %s\n", bestGirl.name, bestGirl.id);
    else
    {
        printf("Absent\n");
    }
    
        if(existBoy)
        printf("%s %s\n", worstBoy.name, worstBoy.id);
    else
    {
        printf("Absent\n");
    }
    if(existBoy&&existGirl)
        printf("%d", bestGirl.score - worstBoy.score);
    else
    {
        printf("NA");
    }
    
        return 0;
}