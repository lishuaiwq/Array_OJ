数组中只出现一次的数字

一个整型数组里除了两个数字之外，其他的数字都出现了偶数次。
请写程序找出这两个只出现一次的数字。

算法1：统计每个数字出现的次数，然后再去找
1.统计最大数最小数
2.开辟空间
3.统计次数
4.找出次数

代码如下：
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		int size = data.size();//统计数组的长度
		int max = data[0];
		int min = data[0];
		for (int i = 1; i<size; i++)
		{
			if (data[i]>max)
				max = data[i];
			if (data[i]<min)
				min = data[i];
		}
		vector<int> v(max - min + 1);//开辟新空间  
		for (int i = 0; i<size; i++)
		{
			v[data[i] - min]++;//标记他们的下标
		}
		int n = v.size();
		int count = 1;
		for (int i = 0; i<n; i++)
		{
			if (v[i] == 1 && count == 1)
			{
				*num1 = (i + min);
				++count;
			}
			else if (v[i] == 1 && count == 2)
			{
				*num2 = (i + min);
			}
		}
	}
};

算法2：使用异或！数组的又一算法思想，异或：a^0=a   a^a=0   
遍历整个数组依次累积异或，最后剩余的结果就是两个不相等的数字异或的结果。
然后找出这个结果最右边不为1的数字，根据这个数字再次划分原数组，从而将两个不相等的数据找到

代码如下：

class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		int size = data.size();
		int num = 0;
		for (int i = 0; i<size; i++)
		{
			num ^= data[i];
		}
		int flag = num&(-num);//找到标志位为1的
		for (int i = 0; i<size; i++)
		{
			if ((flag&data[i]) == 0)
			{
				*num1 ^= data[i];
			}
			else
			{
				*num2 ^= data[i];
			}
		}
	}
};