#include <cstdio>
#include<iostream>
#include <algorithm>
#include <string>
using namespace std;
bool cmp(string a,string b)
{
    return a+b < b+a;
}

int main()
{
    string data[10000];
    int n;
    scanf("%d", &n);
    getchar();
    for(int i = 0; i < n; i++)
    {
        cin >> data[i];
    }
    sort(data, data + n,cmp);
    string ans;
    for(int i = 0; i < n; i++)
    {
        ans += data[i];
    }
    while(!ans.empty()&&ans[0]=='0')
    ans.erase(ans.begin());
    if(ans.empty())
        cout << 0;
    else
        cout << ans;

    getchar();
    getchar();
    return 0;
}