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
     * @param head ListNode类 the head node
     * @return ListNode类
     */
    ListNode* sortInList(ListNode* head) {  //头指针
        // write code here
        if (!head || !head->next)   //若头指针为空或头指针的下一个结点为空，返回头指针
            return head;
        auto res = new ListNode(0), tail = res;  //new一个空链表
        while (head->next)  //如果头结点的下一个节点不为空
        {
            ListNode* smallest = head, * smprev = nullptr;  //小结点
            ListNode* prev = head, * cur = head->next;
            while (cur)
            {
                if (cur->val < smallest->val) //下一节点与当前结点的值进行比较，
                                       //若下一节点的值小于当前节点的值
                                       //将下一节点赋给当节点
                                       //用一个临时的smprev来接受这个prev指针
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