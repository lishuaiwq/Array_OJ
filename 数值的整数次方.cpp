数值的整数次方

给定一个double类型的浮点数base和int类型的整数exponent。求base的exponent次方。

算法：核心的思想就是给的几次方咱们就乘几次

注意事项：次数是负数，或者0，或者正数

代码
首先给出比较挫的代码

class Solution {
public:
	double Power(double base, int exponent) {
		double num = base;
		int n = exponent;
		if (exponent == 0)
			return 1;
		if (exponent>0)
		while (--exponent)
		{
			num = num*base;
		}
		else
		while (++exponent)
		{
			num = num*base;
		}
		if (n<0)
			return 1.0 / num;
		return num;
	}
};

给出优化后的代码可以使用abs求绝对值的 函数进行优化

class Solution {
public:
	double Power(double base, int exponent) {
		double num = base;
		int n = abs(exponent);
		if (n == 0)
			return 1;
		while (--n)
		{
			num = base*num;
		}
		if (exponent<0)
			return 1.0 / num;
		return num;
	}
};