#include<iostream>
using namespace std;

 struct ListNode {
 	int val;
 	struct ListNode *next;
 };


class Solution {
public:
    /**
     *
     * @param head ListNode�� the head node
     * @return ListNode��
     */
    ListNode* sortInList(ListNode* head) {  //ͷָ��
        // write code here
        if (!head || !head->next)   //��ͷָ��Ϊ�ջ�ͷָ�����һ�����Ϊ�գ�����ͷָ��
            return head;
        auto res = new ListNode(0), tail = res;  //newһ��������
        while (head->next)  //���ͷ������һ���ڵ㲻Ϊ��
        {
            ListNode* smallest = head, * smprev = nullptr;  //С���
            ListNode* prev = head, * cur = head->next;
            while (cur)
            {
                if (cur->val < smallest->val) //��һ�ڵ��뵱ǰ����ֵ���бȽϣ�
                                       //����һ�ڵ��ֵС�ڵ�ǰ�ڵ��ֵ
                                       //����һ�ڵ㸳�����ڵ�
                                       //��һ����ʱ��smprev���������prevָ��
                {
                    smallest = cur;
                    smprev = prev;
                }

                prev = cur;
                cur = cur->next;
            }

            if (smprev)
                smprev->next = smallest->next;
            else
                head = head->next;

            tail->next = smallest;
            tail = smallest;
        }

        tail->next = head;
        head->next = nullptr;
        return res->next;
    }
};