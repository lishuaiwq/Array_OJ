数组在排序数组中出现的次数

题目描述
统计一个数字在排序数组中出现的次数。

算法：题目分析，此题为数组题，又是排序数组，对于排序数组我们可以使用二分查找，确定相等的范围，然后
在这个范围中去找等于的次数

代码：
class Solution {
public:
	int GetNumberOfK(vector<int> data, int k)
	{
		int left = 0;
		int right = data.size() - 1;
		int count = 0;
		int flag = 0;
		while (left <= right)
		{
			int mid = ((right - left) >> 1) + left;
			if (data[mid] == k)
			{
				flag = mid;
				count++;
				break;
			}
			else if (k>data[mid])
			{
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		for (int i = left; i <= right; i++)
		{
			if (flag == i)
				continue;
			if (data[i] == k)
			{
				count++;
			}
		}
		return count;
	}
};