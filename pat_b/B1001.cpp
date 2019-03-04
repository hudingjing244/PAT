//题目介绍
/*
1001 害死人不偿命的(3n+1)猜想 (15)（15 分）
卡拉兹(Callatz)猜想：

对任何一个自然数n，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3n+1)砍掉一半。这样一直反复砍下去，最后一定在某一步得到n=1。卡拉兹在1950年的世界数学家大会上公布了这个猜想，传说当时耶鲁大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证(3n+1)，以至于有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展……

我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过1000的正整数n，简单地数一下，需要多少步（砍几下）才能得到n=1？

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。
*/

//思路分析
/*
1.需要一个判断数字奇偶的函数
2.根据奇偶来砍，每砍一次次数+1
3.砍到1时，打印次数
*/

//代码实现
#include <cstdio>


bool isEven(int data)
{
	if(data%2==0)
		return true;
	
	else
	{
		return false;
	}
	
}
int process(int& data)
{
	int count = 0;
	while(data!=1)
	{
		if(isEven(data))
		{
			data /= 2;
			count++;
		}
		else
		{
			data = (3*data + 1) / 2;
			count++;
		}
	}
	return count;
}

int main()
{
	int data = 0;
	scanf("%d", &data);
	printf("%d", process(data));
	getchar();
	getchar();
	return 0;
}