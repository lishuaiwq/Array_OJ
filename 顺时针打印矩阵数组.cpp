//顺时针打印矩阵

//输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字，例如，如果输入如下矩阵： 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 则依次打印出数字1, 2, 3, 4, 8, 12, 16, 15, 14, 13, 9, 5, 6, 7, 11, 10.

class Solution {
public:
	vector<int> printMatrix(vector<vector<int> > matrix)
	{
		int row = matrix.size();//行数
		int col = matrix[0].size();//列树
		int start = 0;//坐上角
		vector<int> s;
		if (col<1 && row<1)
		{
			s.push_back(matrix[0][0]);
			cout << matrix[0][0] << " " << endl;
			exit(0);
		}
		while (col > 2 * start&&row > 2 * start)
		{
			int endx = row - 1 - start;//右下角
			int endy = col - 1 - start;//右下角
			for (int i = start; i <= endy; i++)
			{
				s.push_back(matrix[start][i]);
				cout << matrix[start][i] << " ";     //从左向右走
			}
			if (endx>start)
			{
				for (int i = start + 1; i <= endx; i++)//从上往下走
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