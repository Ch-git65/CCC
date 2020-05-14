#include<stdio.h>
#include<stdlib.h>

//typedef struct seqList
//{
//	//大小确定
//	int _array[10000000];
//	int _size;
//}seqList;

typedef int DataType;
typedef struct seqList
{
	DataType* _array;
	size_t _size;
	size_t _capacity;
}seqList;

void seqListInit(seqList* sl);
void seqListPushBack(seqList* sl, DataType value); //尾插
void seqListPopBack(seqList* sl, DataType value);  //尾删
void seqListPushFront(seqList* sl, DataType value);//头插
void seqListPopFront(seqList* sl);                 //投删
void seqListInsert(seqList* sl, size_t pos, DataType value);//在pos位置前面插入一个数据value
void seqListErase(seqList* sl, size_t pos); //删除pos位置的数据
int seqListFind(seqList* sl, DataType value);
void seqListPrint(seqList* sl);
void checkCapacity(seqList* sl);


