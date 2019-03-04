
#include <cstdio>

double oddd[3];
char choice[3];
void best(int i, double w, double t, double l)
{
    if (w > t && w > l)
    {
        oddd[i] = w;
        choice[i] = 'W';
    }
    else if (t > w && t > l)
    {
        oddd[i] = t;
        choice[i] = 'T';
    }
    else
    {
        oddd[i] = l;
        choice[i] = 'L';
    }
}
int main()
{

    double w, t, l;
    for (int i = 0; i < 3; i++)
    {
        scanf("%lf%lf%lf", &w, &t, &l);
        best(i, w, t, l);
    }
    printf("%c %c %c %.2lf", choice[0], choice[1], choice[2], (oddd[0] * oddd[1] * oddd[2] * 0.65 - 1.0) * 2);
    getchar();
    getchar();
    return 0;
}