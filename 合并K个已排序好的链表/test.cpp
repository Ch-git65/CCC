#include<iostream>
#include<vector>


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:


    //使用优先队列 priority_queue
    /*struct compare
    {
        bool operator()(const ListNode* l, const ListNode* r)
        {
            return l->val > r->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;

        for(auto l:lists)
            if(l) q.push(l);
        if(q.empty())
            return NULL;

        ListNode fake(0);
        ListNode *result = &fake;
        while(!q.empty())
        {
            result->next = q.top();
            q.pop();

            result = result -> next;
            if(result->next)
                q.push(result->next);
        }
        return fake.next;*/


        //使用堆   默认最大堆，改成最小堆，链表依次加入最小堆弹出节点，加入该节点所在链表新节点，不断调整堆
        /*static bool compareless(ListNode* l1, ListNode* l2)
        {
            return l1->val > l2->val;
        }

        ListNode* mergeKLists(vector<ListNode*> &lists)
        {
            ListNode fake(0);
            ListNode *cur = &fake;
            vector<ListNode *> vec;

            int listSize = lists.size();
            for(int i=0; i<listSize; i++)
            {
                if(lists[i])
                    vec.push_back(lists[i]);
            }

            make_heap(vec.begin(), vec.end(), compareless);     ///建堆

            while(vec.size())
            {
                cur->next = vec.front();                        //堆第一个节点first为最小值节点
                pop_heap(vec.begin(), vec.end(), compareless);  //它把first和last-1交换，然后重新生成一个堆
                vec.pop_back();                                 //容器弹出最后一个节点
                cur = cur->next;
                if(cur->next)                                   //添加弹出的最小值的节点所在链表节点last-1位置
                {
                    vec.push_back(cur->next);
                    push_heap(vec.begin(), vec.end(), compareless);//first到last-1是一个有效堆，新加入元素重新生成堆
                }
            }
            return fake.next;
        }*/



        //分治算法，基于两个排序链表的合并，两两合并后继续合并，
        //每一轮复杂度o(n), n为总节点个数， T(n) = 2T(n/2) + o(n),
        //迭代次数为lg(k), 因此复杂度为o(nlgk)

    ListNode* megroTwoSortedLists(ListNode* L1, ListNode* L2)
    {
        if (L1 == nullptr)
            return L2;
        if (L2 == nullptr)
            return L1;
        if (L1->val <= L2->val)
        {
            L1->next = megroTwoSortedLists(L1->next, L2);
            return L1;
        }
        else
        {
            L1->next = megroTwoSortedLists(L1, L2->next);
            return L2;
        }
    }

    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.empty())
            return nullptr;
        while (lists.size() > 1)
        {
            lists.push_back(megroTwoSortedLists(lists[0], lists[1]));
            lists.erase(lists.begin());
            lists.erase(lists.begin());
        }
        return lists.front();
    }
};