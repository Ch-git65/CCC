#include<iostream>
using namespace std;

struct ListNode {
    int val;
    struct ListNode* next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
}; 


class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        /*if(pHead == NULL)
            return NULL;

        ListNode* pNode = pHead;        //当前指针
        ListNode* pReverseHead = NULL;  //新链表的头指针
        ListNode* pPrev = NULL;         //当前指针的前一个结点

        while(pNode != NULL)     //当前结点不为空时才执行
        {
            ListNode* pNext = pNode->next; //链断开之前一定要保存断开位置后边的结点

            if(pNext == NULL)
                pReverseHead = pNode;

            pNode->next = pPrev;  //指针反转
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;*/

        //如果链表为空或者链表中只有一个元素
        if (pHead == NULL || pHead->next == NULL)
            return pHead;

        //先反转后面的链表，走到链表的末端结点
        ListNode* pReverseNode = ReverseList(pHead->next);

        //再将当前节点设置为后面节点的后续节点
        pHead->next->next = pHead;
        pHead->next = NULL;

        return pReverseNode;
    }
};