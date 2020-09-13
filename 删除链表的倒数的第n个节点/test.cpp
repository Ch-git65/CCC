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
     * @param head ListNode类
     * @param n int整型
     * @return ListNode类
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


        //1. 先让一个指针从头走N步
        //2. 然后让另一个指针从头开始走， 当第一个指针走到尾的时候，
        //   第二个指针刚好时倒数第n哥节点， 不过因为要删除倒数第n个节点，
        //   所以要找到倒数第N+1个节点

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

        //如果n的值等于链表的长度， 直接返回去掉头结点的链表
        if (first == NULL)
            return head->next;

        //同时移动两个指针
        while (first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }

        second->next = second->next->next;
        return head;
    }
};