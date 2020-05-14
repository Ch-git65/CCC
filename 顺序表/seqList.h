#include<stdio.h>
#include<stdlib.h>

//typedef struct seqList
//{
//	//��Сȷ��
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
void seqListPushBack(seqList* sl, DataType value); //β��
void seqListPopBack(seqList* sl, DataType value);  //βɾ
void seqListPushFront(seqList* sl, DataType value);//ͷ��
void seqListPopFront(seqList* sl);                 //Ͷɾ
void seqListInsert(seqList* sl, size_t pos, DataType value);//��posλ��ǰ�����һ������value
void seqListErase(seqList* sl, size_t pos); //ɾ��posλ�õ�����
int seqListFind(seqList* sl, DataType value);
void seqListPrint(seqList* sl);
void checkCapacity(seqList* sl);


