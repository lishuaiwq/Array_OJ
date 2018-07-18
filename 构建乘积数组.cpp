构建乘积数组

题目描述
给定一个数组A[0, 1, ..., n - 1],
请构建一个数组B[0, 1, ..., n - 1],
其中B中的元素B[i] = A[0] * A[1] * ...*A[i - 1] * A[i + 1] * ...*A[n - 1]。
不能使用除法。

题目的要求就是，举个例子B[3] = A[0] * A[1] * A[2] * A[4];
B[4] = A[0] * A[1] * A[2] * A[3] * A[5];

要求不能用除法，所以就用了最挫的方法双重for循环啊

class Solution {
public:
	vector<int> multiply(const vector<int>& A)
	{
		vector<int> B;
		int size = A.size();
		int i = 0;
		for (; i<size; i++)
		{
			int sum = 1;
			int j = 0;
			for (; j<size; j++)
			{
				if (i == j)
					continue;
				sum = sum*A[j];
			}
			B.push_back(sum);
		}
		return B;
	}
};