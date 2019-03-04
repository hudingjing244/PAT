//题目介绍
/*
1002 写出这个数 (20)（20 分）
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10^100^。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：

1234567890987654321123456789
输出样例：

yi san wu
*/

//思路分析
/*
1.输入数据不能当成一个整体，每一位是一个独立数字，用数组保存，事先不知道长度，用vector
2.将数组中所有元素相加
3.得到和的各位数字
4.换成拼音
*/

//代码实现
#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string str;
    int sum=0;
    string int2str[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    vector<int> sums;
    cin>>str;
    for(string::iterator it=str.begin();it!=str.end();it++)
    {
        sum=sum+(*it-'0');
    }
    while(sum!=0)
    {
        sums.push_back(sum%10);
        sum /= 10;
    }
    for (vector<int>::iterator it = sums.end()-1; it != sums.begin(); it--)
    {
        cout << int2str[*it];
        cout << ' ';

    }
    cout << int2str[*sums.begin()]<<endl;
    getchar();
    getchar();
    return 0;
}