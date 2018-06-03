二进制中1的个数

输入一个整数，输出该数二进制表示中1的个数。其中负数用补码表示。

算法：注意点就是负数的话我们需要给其&上0x7fffffff将其负号位变为0，

class Solution {
public:
	int  NumberOf1(int n)
	{
		int count = 0;
		int ret = 1;
		if (n<0)
		{
			count = 1;
			n = n & 0x7fffffff;//将负数的负号位置为1
		}
		while (n)
		{
			if (n&ret)
				++count;
			n = n >> 1;
		}
		return count;
	}
};