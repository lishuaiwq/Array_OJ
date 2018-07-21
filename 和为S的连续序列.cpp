https://blog.csdn.net/SunnyYoona/article/details/17021433//解释都在这里自己去看

class Solution {
public:
	vector<vector<int> > FindContinuousSequence(int sum)
	{
		int n = sum / 2;//过了一半就不可能存在了
		int start = 1;
		int end = 2;
		vector<int> s;
		vector<vector<int>> v;
		s.push_back(start);
		s.push_back(end);
		int count = start + end;//两个数的和
		for (; start <= n;)
		{
			if (count == sum)
			{
				v.push_back(s);//满足了将其压进去
				vector<int>::iterator it = s.begin();//用来删除头结点
				count = count - s[0] + (++end);//start继续往后走判断
				s.erase(it);//删除第一个元素
				++start;
				s.push_back(end);
			}
			else if (count>sum)//删除最小的元素
			{
				vector<int>::iterator it = s.begin();
				count = count - s[0];//更新count
				s.erase(it);//删除第一个元素
				start++;
			}
			else//小于的话则需要最大往后加
			{
				count = count + (++end);//更新count
				s.push_back(end);//最后一个压进去
			}
		}
		return v;
	}
};