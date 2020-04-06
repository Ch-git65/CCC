#include<stdio.h>
#include<stdlib.h>

typedef int Type;

typedef struct Node
{
	Type _data;
	struct Node* _next;
	struct Node* _prev;
}Node;

typedef struct List
{
	Node* _header;
}List;

Node* creatNode(Type data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->_prev = node->_next = NULL;
	node->_data = data;
	return node;

}
void listInit(List* lst)
{
	//创建一个头结点，构成循环结构
	lst->_header = creatNode(0);
	lst->_header->_next = lst->_header;
	lst->_header->_prev = lst->_header;
}

void printList(List* lst)
{
	Node* cur = lst->_header->_next;
	while (cur != lst->_header)
	{
		printf("%d",cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void listInsert(Node* pos, Type data)
{
	Node* prev = pos->_prev;
	Node* node = creatNode(data);
	prev->_next = node;
	node->_prev = prev;
	node->_next = pos;
	pos->_prev = node;
}

void listPushBack(List* lst, Type data)
{
	listInsert(lst->_header,data);
}

void listErase(Node* pos)
{
	Node* prev, * next;
	if (pos->_next == pos)
	{
		return;
	}
	prev = pos->_prev;
	next = pos->_next;
	fre(pos);
	prev->_next = next;
	next->_prev = prev;
}

void listPopBack(List* lst)
{
	listErase(lst->_header->_prev);
}

void listPushFront(List* lst, Type data)
{
	listInsert(lst->_header->_next, data);
}

void listPopFront(List* lst)
{
	listErase(lst->_header->_next);
}

void listDesroy(List* lst)
{
	Node* cur = lst->_header->_next;
	while (cur != lst->_header)
	{
		Node* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(lst->_header);
	lst->_header = NULL;
}