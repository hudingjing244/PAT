#include <cstdio>
using namespace std;

int main()
{
    char order[7] = "PATest";
    int cnt[128] = {0};
    char c;

    while ((c = getchar()) != '\n')
        cnt[c]++;

    while (true)
    {
        int printCnt = 0;
        for (int i = 0; i < 6; i++)
        {
            if (cnt[order[i]] > 0)
            {
                putchar(order[i]);
                printCnt++;
                cnt[order[i]]--;
            }
        }
        if (printCnt == 0)
            break;
    }
    getchar();
    getchar();
    return 0;
}