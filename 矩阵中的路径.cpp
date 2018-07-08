//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ����һ��·�������˾����е�ĳһ�����ӣ���֮�����ٴν���������ӡ� ���� a b c e s f c s a d e e ������3 X 4 �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·������Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�

�㷨��ȡ��������㷨������㷨�Ͳ���ϸ�����ˣ����������

class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix == NULL || rows<1 || cols<1 || str == NULL)
			return false;
		//�������Ǿͼ������0��ʼ,���ж�
		bool *arr = new bool[rows*cols]{false};//��������Ƿ��߹���
		int index = 0;//str��λ��
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
		if (str[index] == '\0')//ƥ����ַ���ƥ������
			return true;
		bool ispath = false;
		if (col >= 0 && row >= 0 && col<cols&&row<rows&&!result[row*cols + col] && str[index] == matrix[row*cols + col])
		{
			//�����ǰλ�÷��ϲ���û���߹��Ļ���ô�ͼ�����
			index++;
			result[row*cols + col] = true;
			ispath = DFS(matrix, rows, cols, row + 1, col, str, result, index) || \
				DFS(matrix, rows, cols, row - 1, col, str, result, index) || \
				DFS(matrix, rows, cols, row, col + 1, str, result, index) || \
				DFS(matrix, rows, cols, row, col - 1, str, result, index);
			if (!ispath)
			{
				index--;
				result[row*cols + col] = false;//�߲�ͨû�߹�
			}
		}
		return ispath;
	}

};