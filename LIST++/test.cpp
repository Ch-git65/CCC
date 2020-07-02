namespace bite
{
    // List�Ľڵ���
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T()) : _pPre(nullptr), _pNext(nullptr), _val(val)
        {}
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };

    //List�ĵ�������
    template<class T, class Ref, class Ptr>
    class ListIterator
    {
        typedef ListNode<T>* PNode;
        typedef ListIterator<T, Ref, Ptr> Self;
    public:
        ListIterator(PNode pNode = nullptr) :_pNode(pNode)
        {}
        ListIterator(const Self& l) : _pNode(l._pNode)
        {}
        T& operator*()
        {
            return _pNode->_val;
        }

        T* operator->()
        {
            return &*this;
        }

        Self& operator++()
        {
            _pNode = _pNode->_pNext;
            return *this;
        }

        Self operator++(int)
        {
            Self temp(*this);
            _pNode = _pNode->_pNext;
            return temp;
        }

        Self& operator--()
        {
            _pNode = _pNode->_pPre;
            return *this;
        }

        Self& operator--(int)
        {
            Self temp(*this);
            _pNode = _pNode->_pPre;
            return temp;
        }

        bool operator!=(const Self& l)
        {
            return _pNode != l._pNode;
        }

        bool operator==(const Self& l)
        {
            return !(*this != l);
        }

    private:
        PNode _pNode;

    };

    //list��
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:

        // List�Ĺ���
        list()
        {
            CreateHead();
        }

        list(int n, const T& value = T())
        {
            CreateHead();
            for (int i = 0; i < n; ++i)
                push_back(value);
        }

        template <class Iterator>
        list(Iterator first, Iterator last)
        {
            CreateHead();
            while (first != last)
            {
                push_back(*first);
                ++first;
            }
        }

        list(const list<T>& l)
        {
            CreateHead();
            // ��l�е�Ԫ�ع�����ʱ��temp,Ȼ���뵱ǰ���󽻻�
            list<T> temp(l.cbegin(), l.cend());
            this->swap(temp);
        }

        list<T>& operator=(const list<T> l)
        {
            this->swap(l);
            return *this;
        }

        ~list()
        {
            clear();
            delete _pHead;
            _pHead = nullptr;
        }

        // List Iterator
        iterator begin()
        {
            return iterator(_pHead->_pNext);
        }

        iterator end()
        {
            return iterator(_pHead);
        }

        const_iterator begin()const
        {
            return const_iterator(_pHead->_pNext);
        }

        const_iterator end()const
        {
            return const_iterator(_pHead);
        }

        // List Capacity
        size_t size()const
        {
            size_t size = 0;
            ListNode* p = _pHead->_pNext;
            while (p != _pHead)
            {
                size++;
                p = p->_pNext;
            }
            return size;
        }

        bool empty()const
        {
            return size() == 0;
        }

        // List Access
        T& front()
        {
            assert(!empty());
            return _pHead->_pNext->_val;
        }

        const T& front()const
        {
            assert(!empty());
            return _pHead->_pNext->_val;
        }

        T& back()
        {
            assert(!empty());
            return _pHead->_pPre->_val;
        }

        const T& back()const
        {
            assert(!empty());
            return _pHead->_pPre->_val;
        }


        // List Modify
        void push_back(const T& val)
        {
            insert(begin(), val);

        }

        void pop_back()
        {
            erase(--end());
        }

        void push_front(const T& val)
        {
            insert(begin(), val);
        }

        void pop_front()
        {
            erase(begin());
        }

        // ��posλ��ǰ����ֵΪval�Ľڵ�
        iterator insert(iterator pos, const T& val)
        {
            PNode pNewNode = new Node(val);
            PNode pCur = pos._pNode;
            // �Ƚ��½ڵ����
            pNewNode->_pPre = pCur->_pPre;
            pNewNode->_pNext = pCur;
            pNewNode->_pPre->_pNext = pNewNode;
            pCur->_pPre = pNewNode;
            return iterator(pNewNode);
        }

        // ɾ��posλ�õĽڵ㣬���ظýڵ����һ��λ��
        iterator erase(iterator pos)
        {
            // �ҵ���ɾ���Ľڵ�
            PNode pDel = pos._pNode;
            PNode pRet = pDel->_pNext;

            // ���ýڵ�������в�������ɾ��
            pDel->_pPre->_pNext = pDel->_pNext;
            pDel->_pNext->_pPre = pDel->_pPre;

            delete pDel;
            return iterator(pRet);
        }

        void clear()
        {
            iterator p = begin();
            while (p != end())
            {
                p = erase(p);
            }
        }

        void swap(List<T>& l)
        {
            pNode tmp = _pHead;
            _pHead = l._pHead;
            l._pHead = tmp;
        }

    private:
        void CreateHead()
        {
            _pHead = new Node;
            _pHead->_pPre = _pHead;
            _pHead->_pNext = _pHead;
        }
        PNode _pHead;

    };

}


// constructing lists
#include <iostream>
#include <list>
int main()
{
    std::list<int> l1; // ����յ�l1
    std::list<int> l2(4, 100); // l2�з�4��ֵΪ100��Ԫ��
    std::list<int> l3(l2.begin(), l2.end()); // ��l2��[begin(), end()������ҿ������乹��l3
    std::list<int> l4(l3); // ��l3��������l4
    // ������Ϊ���������乹��l5
    int array[] = { 16,2,77,29 };
    std::list<int> l5(array, array + sizeof(array) / sizeof(int));
    // �õ�������ʽ��ӡl5�е�Ԫ��
    for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
        std::cout << *it << " ";
    std::cout << endl;

    // C++11��Χfor�ķ�ʽ����
    for (auto& e : l5)
        std::cout << e << " ";

    std::cout << endl;
    return 0;
}