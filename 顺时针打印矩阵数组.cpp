//˳ʱ���ӡ����

//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ�����֣����磬����������¾��� 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 �����δ�ӡ������1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		int row = matrix.size();//����
		int col = matrix[0].size();//����
		int start = 0;//���Ͻ�
		vector<int> s;
		if (col<1 && row<1)
		{
			s.push_back(matrix[0][0]);
			cout << matrix[0][0] << " " << endl;
			exit(0);
		}
		while (col > 2 * start&&row > 2 * start)
		{
			int endx = row - 1 - start;//���½�
			int endy = col - 1 - start;//���½�
			for (int i = start; i <= endy; i++)
			{
				s.push_back(matrix[start][i]);
				cout << matrix[start][i] << " ";     //����������
			}
			if (endx>start)
			{
				for (int i = start + 1; i <= endx; i++)//����������
				{
					s.push_back(matrix[i][endy]);
					cout << matrix[i][endy] << " ";
				}
			}
			if (endy > start&&endx > start)
			{
				for (int i = endy - 1; i >= start; i--)
				{
					s.push_back(matrix[endx][i]);
					cout << matrix[endx][i] << " ";
				}
			}
			if (endx - 2 >= start&&endy > start)
			{
				for (int i = endx - 1; i >start; i--)
				{
					s.push_back(matrix[i][start]);
					cout << matrix[i][start] << " ";
				}
			}
			start++;
		}
		return s;
	}
};