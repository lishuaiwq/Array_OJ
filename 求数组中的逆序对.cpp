/ 36:�����е������
//��������:�������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԡ�����һ������,�����������е�����Ե�����P

//�������£�
//����1.����forѭ��ȥ����
//����2.�鲢�����һ��������

//���ڹ鲢�����ڱȽϵ�ʱ��ֱ����������ĺ�����ǰ��ȣ���Ϊ������1 2 3 ;0 1 2�����3����2��ô��һ���Բ���3������ԣ�������Ч�ʱȽϸߣ�ע��Ҳ��Ҫ�鲢����������.
int sum = 0;
void Merge_sort(int* arr, int left, int right, int mid, int *tmp)
{
	int begin1 = mid;
	int begin2 = right;
	int index = right;
	while (begin1 >= left&&begin2 >= mid + 1)
	{
		if (arr[begin1] > arr[begin2])
		{
			sum = sum + (begin2 - mid);
			tmp[index--] = arr[begin1--];
		}
		else
		{
			tmp[index--] = arr[begin2--];
		}
	}
	while (begin1 >= left)
		tmp[index--] = arr[begin1--];
	while (begin2 >= mid + 1)
		tmp[index--] = arr[begin2--];
	memcpy(arr + left, tmp + left, sizeof(int)*(right - left + 1));
}
