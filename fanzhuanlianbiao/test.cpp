#include<iostream>

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
            val(x), next(NULL) {
    }
};
class Solution {
public:
    ListNode* ReverseList(ListNode* pHead) {
        ListNode* cur = pHead;
        ListNode* pre = NULL;
        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};