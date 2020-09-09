#include<iostream>
#include<vector>


 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };


class Solution {
public:


    //ʹ�����ȶ��� priority_queue
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


        //ʹ�ö�   Ĭ�����ѣ��ĳ���С�ѣ��������μ�����С�ѵ����ڵ㣬����ýڵ����������½ڵ㣬���ϵ�����
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

            make_heap(vec.begin(), vec.end(), compareless);     ///����

            while(vec.size())
            {
                cur->next = vec.front();                        //�ѵ�һ���ڵ�firstΪ��Сֵ�ڵ�
                pop_heap(vec.begin(), vec.end(), compareless);  //����first��last-1������Ȼ����������һ����
                vec.pop_back();                                 //�����������һ���ڵ�
                cur = cur->next;
                if(cur->next)                                   //��ӵ�������Сֵ�Ľڵ���������ڵ�last-1λ��
                {
                    vec.push_back(cur->next);
                    push_heap(vec.begin(), vec.end(), compareless);//first��last-1��һ����Ч�ѣ��¼���Ԫ���������ɶ�
                }
            }
            return fake.next;
        }*/



        //�����㷨������������������ĺϲ��������ϲ�������ϲ���
        //ÿһ�ָ��Ӷ�o(n), nΪ�ܽڵ������ T(n) = 2T(n/2) + o(n),
        //��������Ϊlg(k), ��˸��Ӷ�Ϊo(nlgk)

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