地上有一个m行和n列的方格。一个机器人从坐标0, 0的格子开始移动，每一次只能向左，右，上，下四个方向移动一格，但是不能进入行坐标和列坐标的数位之和大于k的格子。 例如，当k为18时，机器人能够进入方格（35, 37），因为3 + 5 + 3 + 7 = 18。但是，它不能进入方格（35, 38），因为3 + 5 + 3 + 8 = 19。请问该机器人能够达到多少个格子？、


算法：也是采取深度优先算法

class Solution {
public:
	bool judege(int k, int a, int b)//判断其位置之和
	{
		int sum = 0;
		int reta = 1;
		int retb = 1;
		while (a)
		{
			sum = sum + a % 10;//取a的个位
			a /= 10;
		}
		while (b)
		{
			sum = sum + b % 10;
			b /= 10;
		}
		if (sum <= k)
			return true;
		else
			return false;
	}
	int DFS(int k, int rows, int cols, int row, int col, bool *arr)
	{
		//到这里就要开始走了
		int count = 0;
		if (row<rows&&col<cols&&row >= 0 && col >= 0 && judege(k, row, col) && !arr[cols*row + col])
		{
			arr[cols*row + col] = true;
			count = 1 + DFS(k, rows, cols, row + 1, col, arr)\
				+ DFS(k, rows, cols, row, col + 1, arr) + \
				DFS(k, rows, cols, row - 1, col, arr) + \
				DFS(k, rows, cols, row, col - 1, arr);
		}
		return count;
	}
	int movingCount(int threshold, int rows, int cols)
	{
		if (rows < 1 || cols < 1)
		{
			return 0;
		}
		bool *arr = new bool[rows*cols];
		memset(arr, 0, rows*cols);
		int count = DFS(threshold, rows, cols, 0, 0, arr);

		delete[] arr;
		return count;
	}
};