#include<stdio.h>
#include<stdlib.h>

typedef char BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType _data;
	struct BinaryTreeNode* _left;
	struct BinaryTreeNode* _right;
}BTNode;

BTNode* BinaryTreeCreate(BTDataType* a, int* pi);

//����������
void BinaryTreeDestory(BTNode** root);

//�������ڵ����
int BinaryTreeSize(BTNode* root);
void BinaryTreeSize2(BTNode* root, int* num);

//������Ҷ�ӽڵ����
int BinaryTreelLeafSize(BTNode* root);

//��������k��ڵ����
int BinaryTreeLevelKSize(BTNode* root, int k);

//����������ֵΪx�Ľڵ�
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

//������ǰ�����
void BinaryTreePrevOrder(BTNode* root);

//�������������
void BinaryTreeInOrder(BTNode* root);

//�������������
void BinaryTreePostOrder(BTNode* root);

//�������
void BinaryTreeLevelOrder(BTNode* root);

//�ж϶������Ƿ�Ϊ��ȫ������
int BinaryTreeComplete(BTNode* root);



