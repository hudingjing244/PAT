#include<iostream>
#include<cctype>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

long long toDecimal(string digits,long long radix)
{
    int temp,index=0;//这种变量随手初始化吧，不然后面忘了出bug
    long long ans=0;
    for(auto it = digits.rbegin(); it != digits.rend(); it++)
    {
        temp=isdigit(*it)?*it-'0':*it-'a'+10;
        ans+=temp*pow(radix,index++);
    }
    return ans;
}

long long getRadix(string digits,long long sum)
{
    char c=*max_element(digits.begin(),digits.end());
    long long low=isdigit(c)?c-'0'+1:c-'a'+11;
    long long high=max(sum,low);//这里直接赋值sum导致没ac
    while(low<=high)
    {
        long long mid=(low+high)/2;
        long long sum2=toDecimal(digits,mid);
        if(sum2>sum||sum2<0)
            high=mid-1;
        else if(sum2==sum)
            return mid;
        else
            low=mid+1;
    }
    return -1;
}
int main()
{
    string n1,n2;
    long long tag,radix;
    cin>>n1>>n2>>tag>>radix;
    long long ans=tag==1?getRadix(n2,toDecimal(n1,radix)):getRadix(n1,toDecimal(n2,radix));
    if(ans==-1)
    cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}
