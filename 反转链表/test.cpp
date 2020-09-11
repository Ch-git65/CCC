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

        ListNode* pNode = pHead;        //��ǰָ��
        ListNode* pReverseHead = NULL;  //�������ͷָ��
        ListNode* pPrev = NULL;         //��ǰָ���ǰһ�����

        while(pNode != NULL)     //��ǰ��㲻Ϊ��ʱ��ִ��
        {
            ListNode* pNext = pNode->next; //���Ͽ�֮ǰһ��Ҫ����Ͽ�λ�ú�ߵĽ��

            if(pNext == NULL)
                pReverseHead = pNode;

            pNode->next = pPrev;  //ָ�뷴ת
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;*/

        //�������Ϊ�ջ���������ֻ��һ��Ԫ��
        if (pHead == NULL || pHead->next == NULL)
            return pHead;

        //�ȷ�ת����������ߵ������ĩ�˽��
        ListNode* pReverseNode = ReverseList(pHead->next);

        //�ٽ���ǰ�ڵ�����Ϊ����ڵ�ĺ����ڵ�
        pHead->next->next = pHead;
        pHead->next = NULL;

        return pReverseNode;
    }
};