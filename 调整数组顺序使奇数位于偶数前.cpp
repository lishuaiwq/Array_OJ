调整数组顺序使奇数位于偶数前

输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于数组的前半部分，所有的数位于位于数组的后半部分，并保证奇数和奇数，偶数和偶数之间的相对位置不变。

解法：可以使用冒泡排序的思想一次筛选出来一个偶数，不过这个内部的循环从后往前开始的

代码

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int size = array.size();
		for (int i = 0; i < size - 1; i++)//控制交换的次数  
		{
			for (int j = size - 1; j>i; j--)
			{
				if (array[j] % 2 != 0 && array[j - 1] % 2 == 0)
				{
					swap(array[j], array[j - 1]);
				}
			}
		}
	}
};

算法2：很简单，但是时间复杂度比较高，用两个队列，一个保存奇数，一个保存偶数，然后再放回去

代码：

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		queue<int> jishu;
		queue<int>  oushu;
		vector<int>::iterator it = array.begin();
		while (it != array.end())
		{
			if (*it % 2 == 0)
				oushu.push(*it);
			else
				jishu.push(*it);
			++it;
		}
		int  i = 0;
		while (!jishu.empty() || !oushu.empty())
		{
			while (!jishu.empty())
			{
				array[i++] = jishu.front();
				jishu.pop();
			}
			while (!oushu.empty())
			{
				array[i++] = oushu.front();
				oushu.pop();
			}
		}
	}
};

