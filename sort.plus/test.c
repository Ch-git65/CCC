/*
k������ʾÿ��k��Ԫ�ع鲢
*/
void mergePass(int* arr, int k, int n, int* temp)
{
	int i = 0;
	//��ǰ����,��2������Ϊk�������кϲ�Ϊ1��
	while (i < n - 2 * k + 1)
	{
		merge(arr, i, i + k - 1, i + 2 * k - 1, temp);
		i += 2 * k;
	}
	//�ϲ�����[i, n - 1]�������벿��[i, i + k - 1]�Լ�����һ���������Ұ벿��[i + k, n - 1]
	if (i < n - k)
	{
		merge(arr, i, i + k - 1, n - 1, temp);
	}

}

// �鲢����ǵݹ��
void MergeSortNonR(int* arr, int length)
{
	int k = 1;
	int* temp = (int*)malloc(sizeof(int) * length);
	while (k < length)
	{
		mergePass(arr, k, length, temp);
		k *= 2;
	}
	free(temp);
}

void TestMergeSort()
{
	int a[] = { 3, 4, 6, 1, 2, 8, 0, 5, 7 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// O(Max(N, ��Χ))
// O(N+��Χ) ʱ�临�Ӷ�
// O(��Χ) �ռ临�Ӷ�
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > max)
			max = a[i];

		if (a[i] < min)
			min = a[i];
	}
	//�ҵ����ݵķ�Χ
	int range = max - min + 1;
	int* countArray = (int*)malloc(range * sizeof(int));
	memset(countArray, 0, sizeof(int) * range);
	//��������λ�ã����Խ�ʡ�ռ�
	for (int i = 0; i < n; ++i)
	{
		countArray[a[i] - min]++;
	}
	//���ܴ����ظ������ݣ��м����漸��
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (countArray[i]--)
		{
			a[index++] = i + min;
		}
	}