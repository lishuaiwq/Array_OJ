��ΪS����������

��Ŀ����
����һ����������������һ������S���������в�����������
ʹ�����ǵĺ�������S������ж�����ֵĺ͵���S��
����������ĳ˻���С�ġ�

���˵������Ӧÿ�����԰����������������С���������

��һ�ַ�������ٷ����ڶ��ַ��������õ�����������ԣ���������е����������Խ������˻�ԽС

�㷨1��
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum)
	{
		if (array.empty())
			return array;
		int a = 0;
		int b = 0;
		int c = 11111;
		int size = array.size();
		for (int i = 0; i<size; i++)
		{
			for (int j = i + 1; j<size; j++)
			{
				if ((array[i] + array[j]) == sum)
				{
					if (array[i] * array[j]>c)
						continue;
					a = array[i];
					b = array[j];
					c = a*b;
				}
			}
		}
		vector<int> s;
		if (a + b != sum)
			return s;
		if (a>b)
		{
			s.push_back(b);
			s.push_back(a);
		}
		else{
			s.push_back(a);
			s.push_back(b);
		}
		return s;
	}
};

�㷨2��
class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> array, int sum) {
		//���������Ŀ��������������������
		//���������������������ľ���Խ���������ĺ͡��˻���ԽС
		vector<int> s;
		int start = 0;
		int end = array.size() - 1;
		while (start<end)
		{
			if (array[start] + array[end] == sum)
			{
				s.push_back(array[start]);
				s.push_back(array[end]);
				break;
			}
			else if ((array[start] + array[end])>sum)//end��ǰ��
			{
				--end;
			}
			else
			{
				++start;
			}
		}
		return s;
	}
};