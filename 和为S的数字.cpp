和为S的两个数字

题目描述
输入一个递增排序的数组和一个数字S，在数组中查找两个数，
使得他们的和正好是S，如果有多对数字的和等于S，
输出两个数的乘积最小的。

输出说明：对应每个测试案例，输出两个数，小的先输出。

第一种方法是穷举法，第二种方法是利用递增数组的特性，这个数组中的两个数差距越大则其乘积越小

算法1：
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		if (array.empty())
			return array;
		int a = 0;
		int b = 0;
		int c = 11111;
		int size = array.size();
		for (int i = 0; i<size; i++)
		{
			for (int j = i + 1; j<size; j++)
			{
				if ((array[i] + array[j]) == sum)
				{
					if (array[i] * array[j]>c)
						continue;
					a = array[i];
					b = array[j];
					c = a*b;
				}
			}
		}
		vector<int> s;
		if (a + b != sum)
			return s;
		if (a>b)
		{
			s.push_back(b);
			s.push_back(a);
		}
		else{
			s.push_back(a);
			s.push_back(b);
		}
		return s;
	}
};

算法2：
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		//充分利用题目给出的条件，递增数组
		//所以整个数组中两个数的距离越大两个数的和、乘积就越小
		vector<int> s;
		int start = 0;
		int end = array.size() - 1;
		while (start<end)
		{
			if (array[start] + array[end] == sum)
			{
				s.push_back(array[start]);
				s.push_back(array[end]);
				break;
			}
			else if ((array[start] + array[end])>sum)//end往前走
			{
				--end;
			}
			else
			{
				++start;
			}
		}
		return s;
	}
};