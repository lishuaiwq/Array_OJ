��������˳��ʹ����λ��ż��ǰ

����һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ�����е�����λ�������ǰ�벿�֣����е���λ��λ������ĺ�벿�֣�����֤������������ż����ż��֮������λ�ò��䡣

�ⷨ������ʹ��ð�������˼��һ��ɸѡ����һ��ż������������ڲ���ѭ���Ӻ���ǰ��ʼ��

����

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		int size = array.size();
		for (int i = 0; i < size - 1; i++)//���ƽ����Ĵ���  
		{
			for (int j = size - 1; j>i; j--)
			{
				if (array[j] % 2 != 0 && array[j - 1] % 2 == 0)
				{
					swap(array[j], array[j - 1]);
				}
			}
		}
	}
};

�㷨2���ܼ򵥣�����ʱ�临�ӶȱȽϸߣ����������У�һ������������һ������ż����Ȼ���ٷŻ�ȥ

���룺

class Solution {
public:
	void reOrderArray(vector<int> &array) {
		queue<int> jishu;
		queue<int>  oushu;
		vector<int>::iterator it = array.begin();
		while (it != array.end())
		{
			if (*it % 2 == 0)
				oushu.push(*it);
			else
				jishu.push(*it);
			++it;
		}
		int  i = 0;
		while (!jishu.empty() || !oushu.empty())
		{
			while (!jishu.empty())
			{
				array[i++] = jishu.front();
				jishu.pop();
			}
			while (!oushu.empty())
			{
				array[i++] = oushu.front();
				oushu.pop();
			}
		}
	}
};

