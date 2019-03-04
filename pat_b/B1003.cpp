//题目介绍
/*
1003 我要通过！(20)（20 分）
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；\

任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；\
如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。

输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (&lt10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：

8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：

YES
YES
YES
YES
NO
NO
NO
NO
*/

//思路分析
/*
1.每个字符串从头遍历，遇到非'P' 'A' 'T'就返回false
2.遇到A继续，若开头的连续A后接的不是P，返回false
3.遇到P继续，其后如果有连续A，继续；如果遇到T，继续，但是T后不为A则返回false
4.顺利遍历完成，返回true

*/

//代码实现
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main()
{
    //保存输入数据
    int n;
    cin >> n;
    string data[n];
    for (int i = 0; i < n;i++)
    {
        cin >> data[i];
    }
    //判断正确与否
    

    getchar();
    getchar();
    return 0;
}