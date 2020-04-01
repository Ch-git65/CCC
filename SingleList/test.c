#include<stdio.h>
#pragma once;
typedef int Type;

typedef struct Node
{
	struct Node* _next;
	Type _data;
}Node;
//ʵ�ֲ���ͷ�����ѭ������
typedef struct SingleList
{
	Node* _head;//��ʾ����������ͷ�ڵ㣬����һ����Ч�����ݵ�λ��
}SingleList;

void singleListInit(SingleList* sl)
{
	//������
	sl->_head = NULL;
}

Node* creatNode(Type data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

void singleListPrint(SingleList* sl)
{
	Node* cur = sl->_head;
	while (cur)
	{
		printf("%d", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void singleListPushFront(SingleList* sl, Type data)
{
	Node* node = creatNode(data);
	//�Ƿ�Ϊ�ձ�
	if (sl->_head == NULL)
	{
		sl->_head = node;
	}
	else {
		node->_next = sl->_head;
		sl->_head = node;
	}
}

void singleListPopFront(SingleList* sl)
{
	if (sl->_head)
	{
		Node* cur = sl->_head;
		sl->_head = cur->_next;
		free(cur);
	}
}

void singleListPushBack(SingleList* sl, Type data)
{
	Node* node = creatNode(data);
	if (sl->_head == NULL)
		sl->_head = node;
	else {
		//�ҵ����һ������
		Node* last = sl->_head;
		while (last->_next)
			last = last->_next;
		last->_next = node;
	}
}

void singleListPopBack(SingleList* sl)
{
	//�ҵ����һ���ڵ㣬���ң��޸ı�ɾ���Ľڵ��ǰ���ڵ��ִ��
	if (sl->_head)
	{
		//�ҵ����һ���ڵ㣬�����Ĺ����У�����prev
		Node* prev = NULL;
		Node* tail = sl->_head;
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		if (tail == sl->_head)
			sl->_head = NULL;
		else
			prev->_next = NULL;
		free(tail);
	}
}