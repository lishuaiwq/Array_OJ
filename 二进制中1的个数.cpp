��������1�ĸ���

����һ��������������������Ʊ�ʾ��1�ĸ��������и����ò����ʾ��

�㷨��ע�����Ǹ����Ļ�������Ҫ����&��0x7fffffff���为��λ��Ϊ0��

class Solution {
public:
	int  NumberOf1(int n)
	{
		int count = 0;
		int ret = 1;
		if (n<0)
		{
			count = 1;
			n = n & 0x7fffffff;//�������ĸ���λ��Ϊ1
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