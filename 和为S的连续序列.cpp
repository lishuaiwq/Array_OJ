https://blog.csdn.net/SunnyYoona/article/details/17021433//���Ͷ��������Լ�ȥ��

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		int n = sum / 2;//����һ��Ͳ����ܴ�����
		int start = 1;
		int end = 2;
		vector<int> s;
		vector<vector<int>> v;
		s.push_back(start);
		s.push_back(end);
		int count = start + end;//�������ĺ�
		for (; start <= n;)
		{
			if (count == sum)
			{
				v.push_back(s);//�����˽���ѹ��ȥ
				vector<int>::iterator it = s.begin();//����ɾ��ͷ���
				count = count - s[0] + (++end);//start�����������ж�
				s.erase(it);//ɾ����һ��Ԫ��
				++start;
				s.push_back(end);
			}
			else if (count>sum)//ɾ����С��Ԫ��
			{
				vector<int>::iterator it = s.begin();
				count = count - s[0];//����count
				s.erase(it);//ɾ����һ��Ԫ��
				start++;
			}
			else//С�ڵĻ�����Ҫ��������
			{
				count = count + (++end);//����count
				s.push_back(end);//���һ��ѹ��ȥ
			}
		}
		return v;
	}
};