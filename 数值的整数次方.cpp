��ֵ�������η�

����һ��double���͵ĸ�����base��int���͵�����exponent����base��exponent�η���

�㷨�����ĵ�˼����Ǹ��ļ��η����Ǿͳ˼���

ע����������Ǹ���������0����������

����
���ȸ����Ƚϴ�Ĵ���

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

�����Ż���Ĵ������ʹ��abs�����ֵ�� ���������Ż�

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