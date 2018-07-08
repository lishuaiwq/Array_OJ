//请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一个格子开始，每一步可以在矩阵中向左，向右，向上，向下移动一个格子。如果一条路径经过了矩阵中的某一个格子，则之后不能再次进入这个格子。 例如 a b c e s f c s a d e e 这样的3 X 4 矩阵中包含一条字符串"bcced"的路径，但是矩阵中不包含"abcb"路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入该格子。

算法采取深度优先算法。这个算法就不详细描述了，看代码理解

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows<1 || cols<1 || str == NULL)
			return false;
		//这里我们就假设其从0开始,即判断
		bool *arr = new bool[rows*cols]{false};//用来标记是否走过了
		int index = 0;//str的位置
		bool istrue = false;
		for (int i = 0; i<rows; i++)
		{
			for (int j = 0; j<cols; j++)
			{
				istrue = DFS(matrix, rows, cols, i, j, str, arr, index);
				if (istrue)
					break;
			}
		}
		delete[] arr;
		return istrue;
	}
	bool DFS(char* matrix, int rows, int cols, int row, int col, char* str, bool *result, int &index)
	{
		if (str[index] == '\0')//匹配的字符串匹配完了
			return true;
		bool ispath = false;
		if (col >= 0 && row >= 0 && col<cols&&row<rows&&!result[row*cols + col] && str[index] == matrix[row*cols + col])
		{
			//如果当前位置符合并且没有走过的话那么就继续走
			index++;
			result[row*cols + col] = true;
			ispath = DFS(matrix, rows, cols, row + 1, col, str, result, index) || \
				DFS(matrix, rows, cols, row - 1, col, str, result, index) || \
				DFS(matrix, rows, cols, row, col + 1, str, result, index) || \
				DFS(matrix, rows, cols, row, col - 1, str, result, index);
			if (!ispath)
			{
				index--;
				result[row*cols + col] = false;//走不通没走过
			}
		}
		return ispath;
	}

};