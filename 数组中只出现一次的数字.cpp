������ֻ����һ�ε�����

һ�����������������������֮�⣬���������ֶ�������ż���Ρ�
��д�����ҳ�������ֻ����һ�ε����֡�

�㷨1��ͳ��ÿ�����ֳ��ֵĴ�����Ȼ����ȥ��
1.ͳ���������С��
2.���ٿռ�
3.ͳ�ƴ���
4.�ҳ�����

�������£�
class Solution {
public:
	void FindNumsAppearOnce(vector<int> data, int* num1, int *num2)
	{
		int size = data.size();//ͳ������ĳ���
		int max = data[0];
		int min = data[0];
		for (int i = 1; i<size; i++)
		{
			if (data[i]>max)
				max = data[i];
			if (data[i]<min)
				min = data[i];
		}
		vector<int> v(max - min + 1);//�����¿ռ�  
		for (int i = 0; i<size; i++)
		{
			v[data[i] - min]++;//������ǵ��±�
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

�㷨2��ʹ������������һ�㷨˼�룬���a^0=a   a^a=0   
�����������������ۻ�������ʣ��Ľ��������������ȵ��������Ľ����
Ȼ���ҳ����������ұ߲�Ϊ1�����֣�������������ٴλ���ԭ���飬�Ӷ�����������ȵ������ҵ�

�������£�

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
		int flag = num&(-num);//�ҵ���־λΪ1��
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