#include"seqList.h"

void seqListInit(seqList* sl)
{
	//初始化数组
	sl->_array = (int*)malloc(sizeof(DataType)* 4);
	sl->_capacity = 4;
	sl->_size = 0;
}

void seqListPushBack(seqList* sl, DataType value) //尾插
{
	/*checkCapacity(sl);
	sl->_array[sl->_size++] = value;*/
	seqListInsert(sl, sl->_size, value);
}

void seqListPopBack(seqList* sl, DataType value)  //尾删
{
	/*if (sl->_size)
		--sl->_size;*/
	seqListErase(sl, sl->_size-1);
}

void seqListPushFront(seqList* sl, DataType value)//头插
{
	/*checkCapacity(sl);
	size_t end = sl->_size;
	while (end > 0)
	{
		sl->_array[end] = sl->_array[end - 1];
		--end;
	}
	sl->_array[0] = value;
	++sl->_size;*/
	seqListInsert(sl, 0, value);
}

void seqListPopFront(seqList* sl)              //投删
{
	/*if (sl->_size)
	{
		size_t start = 1;
		while (start < sl->_size)
		{
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;*/
	}
	seqListErase(sl,0);
}

void seqListInsert(seqList* sl, size_t pos, DataType value)//在pos位置前面插入一个数据value
{
	if (pos <= sl->_size)
	{
		checkCapacity(sl);
		size_t end = sl->_size;
		while (end > pos)
		{
			sl->_array[end] = sl->_array[end - 1];
			--end;
		}
		sl->_arraay[end] = value;
		++sl->_size;
	}
}

void seqListErase(seqList* sl, size_t pos)//删除pos位置的数据
{
	if (pos < sl->_size)
	{
		size_t start = pos + 1;
		while (start < sl->_size)
		{
			sl->_array[start - 1] = sl->_array[start];
			++start;
		}
		--sl->_size;
	}
}
int seqListFind(seqList* sl, DataType value)
{
	for (int i = 0; i < sl->_size; i++)
	{
		if (sl->_array[i] == value)
		{
			return i;
		}
		return -1;
	}
}

void seqListPrint(seqList* sl)
{
	for (size_t i = 0; i < sl->_size; ++i)
	{
		printf("%d ", sl->_array[i]);
	}
	printf("\n");
}

void checkCapacity(seqList* sl)
{
	if (sl->_size == sl->_capacity)
	{
		sl->_capacity *= 2;
		/*DataType* newArray = (DataType*)malloc(sizeof(DataType) * sl->_capacity);
		memcpy(newArray, sl->_array, sl->_size * sizeof(DataType));
		free(sl->_array);
		sl->_array = newArray;*/
		sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType) * sl->_capacity);
	}
}