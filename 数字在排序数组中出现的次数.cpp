���������������г��ֵĴ���

��Ŀ����
ͳ��һ�����������������г��ֵĴ�����

�㷨����Ŀ����������Ϊ�����⣬�����������飬���������������ǿ���ʹ�ö��ֲ��ң�ȷ����ȵķ�Χ��Ȼ��
�������Χ��ȥ�ҵ��ڵĴ���

���룺
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