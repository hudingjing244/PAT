//这道题涉及很多结构体以及字符串处理的语言细节

#include <cstdio>

int main()
{
    int n;
    struct stu
    {
        char name[11];
        char id[11];
        int score;
    } min, max, temp;
    
//别设置反了
    min.score = 101;
    max.score = -1;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s%d", temp.name, temp.id, &temp.score); //%s ，即不包含空格，tab的最长匹配串
        if (temp.score < min.score)
        {
            min = temp; //数组不能这么拷贝，因为数组名是指针；结构体变量名就当成普通类型变量一样拷贝
        }
        if (temp.score > max.score)
        {
            max = temp;
        }
       
    }
       printf("%s %s\n", max.name, max.id);
       printf("%s %s\n", min.name, min.id);
    getchar();
    getchar();
    return 0;
}
