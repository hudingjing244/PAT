#include <cstdio>
#include <cctype>

int main()
{
    int mostCnt= 0;
    char c;
    int freq[128] = {0};
    while((c=getchar())!='\n')
    {
        if(isalpha(c))
        {
            freq[tolower(c)]++;
            mostCnt = mostCnt < freq[tolower(c)] ? freq[tolower(c)] : mostCnt;
        }   
    }
    for(int i = 'a'; i <= 'z'; i++)
    {
        if(freq[i]==mostCnt)
        {
             printf("%c ", i);
             break;
        }
           
    }
    printf("%d", mostCnt);
    return 0;
}