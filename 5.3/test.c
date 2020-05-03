
void shellSort(int* array, int n)
{
	//gap:步长
	int gap = n;
	//多轮插入排序
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		//gap=gap/2;
		//一轮插入排序
		for (int i = 0; i < n - gap; ++i)
		{
			//通过步长gap进行逻辑分组
			//组内进行插入排序
			//不同组的元素交替进行排序
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
