�����˻�����

��Ŀ����
����һ������A[0, 1, ..., n - 1],
�빹��һ������B[0, 1, ..., n - 1],
����B�е�Ԫ��B[i] = A[0] * A[1] * ...*A[i - 1] * A[i + 1] * ...*A[n - 1]��
����ʹ�ó�����

��Ŀ��Ҫ����ǣ��ٸ�����B[3] = A[0] * A[1] * A[2] * A[4];
B[4] = A[0] * A[1] * A[2] * A[3] * A[5];

Ҫ�����ó��������Ծ��������ķ���˫��forѭ����

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