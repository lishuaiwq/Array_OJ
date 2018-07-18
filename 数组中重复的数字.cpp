数组中重复的数字

题目描述
在一个长度为n的数组里的所有数字都在0到n - 1的范围内。
数组中某些数字是重复的，但不知道有几个数字是重复的。
也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组{ 2, 3, 1, 0, 2, 5, 3 }，那么对应的输出是第一个重复的数字2。

自己的算法思想：使用set

将数组中的元素插入set，然后在查找，如果找到了则就返回这个元素，没有则迭代器为end()
给出代码

bool duplicate(int numbers[], int length, int* duplication) 
{
	set<int>  s;
	set<int>::iterator it;
	for (int i = 0; i<length; i++)
	{
		it = s.find(numbers[i]);//找到了则返回
		if (it != s.end())
		{
			*duplication = numbers[i];
			return true;
		}
		s.insert(numbers[i]);
	}
	return false;
}
