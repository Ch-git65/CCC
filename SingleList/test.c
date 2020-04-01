#include<stdio.h>
#pragma once;
typedef int Type;

typedef struct Node
{
	struct Node* _next;
	Type _data;
}Node;
//实现不带头单向非循环链表
typedef struct SingleList
{
	Node* _head;//表示链表真正的头节点，即第一个有效的数据的位置
}SingleList;

void singleListInit(SingleList* sl)
{
	//空链表
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
	//是否为空表
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
		//找到最后一个数据
		Node* last = sl->_head;
		while (last->_next)
			last = last->_next;
		last->_next = node;
	}
}

void singleListPopBack(SingleList* sl)
{
	//找到最后一个节点，并且，修改被删除的节点的前驱节点的执行
	if (sl->_head)
	{
		//找到最后一个节点，遍历的过程中，更新prev
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