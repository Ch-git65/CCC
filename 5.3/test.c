
void shellSort(int* array, int n)
{
	//gap:����
	int gap = n;
	//���ֲ�������
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gap=gap/2;
		//һ�ֲ�������
		for (int i = 0; i < n - gap; ++i)
		{
			//ͨ������gap�����߼�����
			//���ڽ��в�������
			//��ͬ���Ԫ�ؽ����������
			int end = i;
			int key = array[end + gap];
			while (end >= 0 && array[end] > key)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}
