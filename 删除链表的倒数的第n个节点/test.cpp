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
     * @param head ListNode��
     * @param n int����
     * @return ListNode��
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // write code here
        /*if(head == NULL)
            return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        head = dummy;

        ListNode* slow = head;
        ListNode* fast = head;
        for(int i=0; i<n; i++)
            fast = fast -> next;

        while(fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        return dummy->next;*/


        //1. ����һ��ָ���ͷ��N��
        //2. Ȼ������һ��ָ���ͷ��ʼ�ߣ� ����һ��ָ���ߵ�β��ʱ��
        //   �ڶ���ָ��պ�ʱ������n��ڵ㣬 ������ΪҪɾ��������n���ڵ㣬
        //   ����Ҫ�ҵ�������N+1���ڵ�

        /*if(head == nullptr)
            return nullptr;
        ListNode*fast = head;
        ListNode*slow = head;
        ListNode*p = nullptr;
        while(n--)
            fast = fast->next;

        if(fast == nullptr)
        {
            p = head->next;
            delete head;
            return p;
        }

        while(fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }

        p = slow->next;
        slow->next = slow->next->next;
        delete p ;
        return head;*/



        ListNode* first = head;
        ListNode* second = head;
        while (n--)
            first = first->next;

        //���n��ֵ��������ĳ��ȣ� ֱ�ӷ���ȥ��ͷ��������
        if (first == NULL)
            return head->next;

        //ͬʱ�ƶ�����ָ��
        while (first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        return head;
    }
};