����


��Ŀ����
��ֻ����������2��3��5��������������Ugly Number����
����6��8���ǳ�������14���ǣ���Ϊ������������7�� 
ϰ�������ǰ�1�����ǵ�һ���������󰴴�С�����˳��ĵ�N��������

�㷨��

��1�������� 1,
��2�������� 1 * 2 = 2, ��1������ * 2
��3�������� 1 * 3 = 3, ��1������ * 3
��4�������� 2 * 2 = 4, ��2������ * 2
��5�������� 1 * 5 = 5, ��1������ * 5
��6�������� 2 * 3 = 6, ��2������ * 3

������w2, w3, w5�ֱ��¼Ϊ2��3��5���ֵ�λ�ã���ʼ��Ϊ0��
���������ΪA �ʼ����Ҳֻ�г���1�� 
��2������Ϊmin(A[w2]2, A[w3]3, A[w5]5)��
Ȼ����СֵΪA[w2]2������w2���������һλ��
������һ�ξ��Ǽ����2����������2��
�Ӷ���֤�˳������еĲ��ϵ�����ֱ���ҵ���index������

���룺

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