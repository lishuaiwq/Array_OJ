�������ظ�������

��Ŀ����
��һ������Ϊn����������������ֶ���0��n - 1�ķ�Χ�ڡ�
������ĳЩ�������ظ��ģ�����֪���м����������ظ��ġ�
Ҳ��֪��ÿ�������ظ����Ρ����ҳ�����������һ���ظ������֡�
���磬������볤��Ϊ7������{ 2, 3, 1, 0, 2, 5, 3 }����ô��Ӧ������ǵ�һ���ظ�������2��

�Լ����㷨˼�룺ʹ��set

�������е�Ԫ�ز���set��Ȼ���ڲ��ң�����ҵ�����ͷ������Ԫ�أ�û���������Ϊend()
��������

bool duplicate(int numbers[], int length, int* duplication) 
{
	set<int>  s;
	set<int>::iterator it;
	for (int i = 0; i<length; i++)
	{
		it = s.find(numbers[i]);//�ҵ����򷵻�
		if (it != s.end())
		{
			*duplication = numbers[i];
			return true;
		}
		s.insert(numbers[i]);
	}
	return false;
}
