#include"heap.h"

void Swap(HPDataType* array, int left, int right)
{
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

void heapCreat(Heap* hp, HPDataType* array, int size)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = size;
	//建堆，从最后一个非叶子节点开始
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, size, parent);
	}
}
//大堆的向下调整
//parent 起始调整的位置
void shiftDown(HPDataType* array, int size, int parent)
{
	//左孩子的位置
	int child = 2 * parent + 1;
	while (child < size)
	{
		//从左右孩子孩子中选一个最大的
		if (child + 1 < size && array[child + 1] > array[child])
		{
			++child;
			//和父节点比较
			if (array[child] > array[parent])
			{
				Swap(array, child, parent);
				//更新
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
}

//大堆向上调整
void shiftUp(HPDataType* array, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (array[child] > array[parent])
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void shiftDownL(HPDataType* array, int size, int parent)
{
	//左右孩子位置
	int child = 2 * parent + 1;
	while (child < parent)
	{
		//从左右孩子孩子中选一个最小的
		if (child + 1 < size && array[child + 1] < array[child])
		{
			++child;
			if (array[child] > array[parent])
			{
				Swap(array, child, parent);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}
}

void shiftUpL(HPDataType* array, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (array[child] < array[parent])
		{
			Swap(array, child, parent);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void heapPush(Heap* hp, HPDataType data)
{
	if (hp->_size == hp->_capacity)
	{
		hp->_capacity *= 2;
		hp->_array = (HPDataType*)realloc(hp->_array, hp->_capacity * sizeof(HPDataType));
	}
	//尾插
	hp->_array[hp->_size++] = data;
	shiftUp(hp->_array, hp->_size - 1);
}

void heapPop(Heap* hp)
{
	Swap(hp->_array, 0, hp->_size - 1);
	hp->_size--;
	shiftDown(hp->_array, hp->_size - 1, 0);
}

HPDataType heapTop(Heap* hp)
{
	return hp->_array[0];
}

int heapEmpty(Heap* hp)
{
	if (hp->_size == 0)
		return 1;
	return 0;
}

void heapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d", hp->_array[i]);
	}
	printf("\n");
}