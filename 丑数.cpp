丑数


题目描述
把只包含质因子2、3和5的数称作丑数（Ugly Number）。
例如6、8都是丑数，但14不是，因为它包含质因子7。 
习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。

算法：

第1个丑数是 1,
第2个丑数是 1 * 2 = 2, 第1个丑数 * 2
第3个丑数是 1 * 3 = 3, 第1个丑数 * 3
第4个丑数是 2 * 2 = 4, 第2个丑数 * 2
第5个丑数是 1 * 5 = 5, 第1个丑数 * 5
第6个丑数是 2 * 3 = 6, 第2个丑数 * 3

我们以w2, w3, w5分别记录为2、3、5出现的位置，初始都为0，
设丑数序列为A 最开始我们也只有丑数1， 
第2个丑数为min(A[w2]2, A[w3]3, A[w5]5)，
然后最小值为A[w2]2，所以w2可以向后移一位，
这样下一次就是计算第2个丑数乘以2，
从而保证了丑数序列的不断递增，直到找到第index丑数。

代码：

class Solution {
public:
	int Min(int a, int b, int c)
	{
		return (a>b ? b : a)>c ? c : (a>b ? b : a);
	}
	int GetUglyNumber_Solution(int index)
	{
		if (index == 0)
			return 0;
		int *arr = new int[index];
		arr[0] = 1;
		int step = 1;
		int *p2 = arr;
		int *p3 = arr;
		int *p5 = arr;
		while (step<index)
		{
			int min = Min(*p2 * 2, *p3 * 3, *p5 * 5);
			arr[step] = min;
			while (*p2 * 2 <= arr[step])
				p2++;
			while (*p3 * 3 <= arr[step])
				p3++;
			while (*p5 * 5 <= arr[step])
				p5++;
			step++;
		}
		int ret = arr[step - 1];
		delete[] arr;
		return ret;
	}
};