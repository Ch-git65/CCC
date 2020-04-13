#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* _array;
	int _size;
	int _capacity;
}Heap;

void Swap(HPDataType* array, int left, int right)
{
	int tmp = array[left];
	array[left] = array[right];
	array[right] = tmp;
}

void shiftDown(HPDataType* array, int size, int parent)
{
	//左孩子位置
	int child = 2 * parent + 1;
	while (child < size)
	{
		//从左右孩子中选一个最小的
		if (child + 1 < size && array[child + 1] < array[child])
		{
			++child;
		}
		//和父节点比较
		if (array[child] < array[parent])
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
void heapCreat(Heap* hp, HPDataType* array, int size)
{
	hp->_array = (HPDataType*)malloc(sizeof(HPDataType) * size);
	memcpy(hp->_array, array, sizeof(HPDataType) * size);
	hp->_size = size;
	hp->_capacity = size;
	//建堆，从最后一个非叶子节点开始建堆 (size-2)/2
	for (int parent = (size - 2) / 2; parent >= 0; parent--)
	{
		shiftDown(hp->_array, size, parent);
	}
}

void shiftUp(HPDataType* array, int child)
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

void heapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; ++i)
	{
		printf("%d ", hp->_array[i]);
	}
	printf("\n");
}

void test()
{
	int array[11] = { 100,50,30,20,25,18,10,5,15,21,23 };
	Heap hp;
	heapCreat(&hp, array, 11);
	heapPrint(&hp);
}

int main()
{
	test();
	return 0;
}