#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

//��̬˳���
typedef int DataType;
typedef struct seqList
{
	DataType* _array;
	size_t _size;     //Ԫ�ظ���
	size_t _capacity;  //����
}seqList;

//��ʼ������
void seqListInit(seqList* sl)
{
	sl->_array = (int*)malloc(sizeof(DataType) * 4);
	sl->_capacity = 4;
	sl->_size = 0;
}

//����
void checkCapacity(seqList* sl)
{
	if (sl->_size == sl->_capacity)
	{
		sl->_capacity *= 2;
		sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType) * sl->_capacity);
	}
}
// ��popλ����ǰ����һ������value
void seqListInsert(seqList * sl, size_t pos, DataType value)
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
		sl->_array[pos] = value;
		++sl->_size;
	}
}
//ɾ��posλ�õ�����
void seqListErase(seqList* sl, size_t pos)
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
//pushBack  β��
void seqListPushBack(seqList* sl, DataType value)
{
	seqListInsert(sl,sl->_size,value);
}

//PopBack  βɾ
void seqListPopBack(seqList* sl)
{
	seqListErase(sl, sl->_size - 1);
}

//PushFront ͷ��
void seqListPushFront(seqList* sl, DataType value)
{
	seqListInsert(sl, 0, value);
}

////����
//void checkCapacity(seqList* sl)
//{
//	if (sl->_size == sl->_capacity)
//	{
//		sl->_capacity *= 2;
//		sl->_array = (DataType*)realloc(sl->_array, sizeof(DataType) * sl->_capacity);
//	}
//}

//PopFrontͷɾ
void seqListPopFront(seqList* sl)
{
	seqListErase(sl, 0);
}

////��popλ����ǰ����һ������value
//void seqListInsert(seqList* sl, size_t pos, DataType value)
//{
//	if (pos <= sl->_size)
//	{
//		checkCapacity(sl);
//		size_t end = sl->_size;
//		while (end > pos)
//		{
//			sl->_array[end] = sl->_array[end - 1];
//			--end;
//		}
//		sl->_array[pos] = value;
//		++sl->_size;
//	}
//}
//
////ɾ��posλ�õ�����
//void seqListErase(seqList* sl, size_t pos)
//{
//	if (pos < sl->_size)
//	{
//		size_t start = pos + 1;
//		while (start < sl->_size)
//		{
//			sl->_array[start - 1] = sl->_array[start];
//			++start;
//		}
//		--sl->_size;
//	}
//}

int seqListFind(seqList* sl, DataType value)
{
	for (int i = 0; i<sl->_size; ++i)
	{
		if (sl->_array[i] == value)
		{
			return i;
		}
	}
	return -1;
}

void seqListPrint(seqList* sl)
{
	for (size_t i = 0; i < sl->_size; ++i)
	{
		printf("%d",sl->_array[i]);
	}
	printf("\n");
}

int removeElement(int* nums, int numsSize, int val)
{
	//int* newA = (int*)mealloc(sizeof(numsSize * sizeof(int)));
	int idx = 0;
	for (int i = 0; i < numsSize; ++i)
	{
		if (nums[i] != val)
			nums[idx++] = nums[i];
	}
	//memcpy(nums, newA, sizeof(int) * idx);
	//free(newA);
	return idx;
}

void test()
{
	seqList sl;
	seqListInit(&sl);
	seqListPushBack(&sl, 1);
	seqListPushBack(&sl, 2);
	seqListPushBack(&sl, 3);
	seqListPrint(&sl);
	seqListPopBack(&sl);
	seqListPrint(&sl);
	seqListPopBack(&sl);
	seqListPrint(&sl);
	seqListPopBack(&sl);
	seqListPrint(&sl);
	seqListPopBack(&sl);
	seqListPrint(&sl);
}
int main()
{
	test();
	int nums[] = { 0,1,2,2,3,0,4,2 };
	int number = removeElement(nums, sizeof(nums) / sizeof(nums[0]), 2);
	for (int i = 0; i < number; ++i)
	{
		printf("%d", nums[i]);
	}
	printf("\n");
	return 0;
}