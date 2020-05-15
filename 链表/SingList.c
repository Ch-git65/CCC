#include<stdio.h>
#include"SingList.h"

void singleListInit(SingleList* sl)
{
	//¿ÕÁ´±í
	sl->_head = NULL;
}

Node* creatNode(Type data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_data = data;
	node->_next = NULL;
	return node;
}

void singleListPront(SingleList* sl)
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
	if (sl->_head == NULL)
	{
		sl->_head = node;
	}
	else
	{
		node->_next = sl->_head;
		sl->_head = node;
	}
}

void singleListPopFront(SingleList* sl)
{
	if(sl->_head)
	{
		Node* cur = sl->_head;
		sl->_head = cur->_next;
		free(cur);
	}
}

void singleListPop(Node** head)
{
	if (*head)
	{
		Node* newH = (*head)->_next;
		free(*head);
		*head = newH;
	}
}

//´íÎó½Ó¿Ú
void singleListPop1(Node* head)
{
	if (head)
	{
		Node* newH = head->_next;
		free(head);
		head = newH;
	}
}				

void singleListPushBack(SingleList* sl, Type data)
{
	Node* node = creatNode(data);
	if (sl->_head == NULL)
	{
		sl->_head = node;
	}
	else
	{
		Node* last = sl->_head;
		while (last->_next)
		{
			last = last->_next;
		}
		last->_next = node;
	}
}

void singleListPopBack(SingleList* sl)
{
	if (sl->_head)
	{
		Node* prev = NULL;
		Node* tail = sl->_head;
		while (tail->_next)
		{
			prev = tail;
			tail = tail->_next;
		}
		if (tail == sl->_head)
		{
			sl->_head = NULL;
		}
		else
		{
			prev->_next = NULL;
		}
		free(tail);
	}
}

void singleListInsertAfter(Node* pos, Type data)
{
	if (pos == NULL)
		return;
	Node* newNode = creatNode(data);
	newNode->_next = creatNode(data);
	pos->_next = newNode;
}

void singleListEraseAfter(Node* pos)
{
	Node* next;
	if (pos == NULL)
		return;
	next = pos->_next;
	if (next)
	{
		pos->_next = next->_next;
		free(next);
	}
}

Node* find(SingleList* sl, Type data)
{
	Node* cur = sl->_head;
	while (cur)
	{
		if (cur->_data == data)
		{
			return cur;
		}
		cur = cur->_next;
	}
	return NULL;
}

void singleListDestroy(SingleList* sl)
{
	Node* cur = sl->_head;
	while (cur)
	{
		Node* cur = sl->_head;
		free(cur);
		cur = cur->_next;
	}
}