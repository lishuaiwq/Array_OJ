������һ��m�к�n�еķ���һ�������˴�����0, 0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ�񣬵��ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35, 37������Ϊ3 + 5 + 3 + 7 = 18�����ǣ������ܽ��뷽��35, 38������Ϊ3 + 5 + 3 + 8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ���


�㷨��Ҳ�ǲ�ȡ��������㷨

class Solution {
public:
	bool judege(int k, int a, int b)//�ж���λ��֮��
	{
		int sum = 0;
		int reta = 1;
		int retb = 1;
		while (a)
		{
			sum = sum + a % 10;//ȡa�ĸ�λ
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
		//�������Ҫ��ʼ����
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