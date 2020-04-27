//typedef int DataType;
//struct Node
//{
//	struct Node* _firstChild1; //第一个孩子结点
//	struct Node* _pNextBrother;//指向棋下一个兄弟结点
//	DataType _data;            //结点中的数据域
//};

#include<stdio.h>
#include<stdlib.h>
typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* src, int n, int* pi)
{
	if (src[*pi] == '#' || *pi >= n)
	{
		(*pi)++;
		return NULL;
	}

	BTNode* cur = (BTNode*)malloc(sizeof(BTNode));
	cur->_data = src[s_n];
	(*pi)++;

	cur->_left = BinaryTreeCreateExe(src);
	cur->_right = BinaryTreeCreateExe(src);

	return cur;
}

void BinaryTreePrevOrder(BTNode* root)
{
	if (root)
	{
		putchar(root->_data);
		BinaryTreePrevOrder(root->_left);
		BinaryTreePrevOrder(root->_right);
	}
}

void BinaryTreeInOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreeInOrder(root->_left);
		putchar(root->_data);
		BinaryTreeInOrder(root->_right);
	}
}

void BinaryTreePostOrder(BTNode* root)
{
	if (root)
	{
		BinaryTreePostOrder(root->_left);
		BinaryTreePostOrder(root->_right);
		putchar(root->_data);
	}
}

void BinaryTreeDestory(BTNode** root)
{
	if (*root)
	{
		BinaryTreeDestory((*root)->_left);
		BinaryTreeDestory((*root)->_right);
		free(*root);
		*root = NULL;
	}
}

void BinaryTreeLevelOrder(BTNode* root)
{
	Queue qu;
	BTNode* cur;

	QueueInit(&qu);

	QueuePush(&qu, root);

	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);

		putchar(cur->_data);

		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}

		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}

		QueuePop(&qu);
	}

	QueueDestory(&qu);
}

int BinaryTreeComplete(BTNode* root)
{
	Queue qu;
	BTNode* cur;
	int tag = 0;
	QueueInit(&qu);
	QueuePush(&qu, root);
	while (!QueueIsEmpty(&qu))
	{
		cur = QueueTop(&qu);
		putchar(cur->_data);
		if (cur->_right && !cur->_left)
		{
			return 0;
		}

		if (tag && (cur->_right || cur->_left))
		{
			return 0;
		}

		if (cur->_left)
		{
			QueuePush(&qu, cur->_left);
		}

		if (cur->_right)
		{
			QueuePush(&qu, cur->_right);
		}
		else
		{
			tag = 1;
		}
		QueuePop(&qu);
	}
	QueueDestory(&qu);
	return 1;
}
