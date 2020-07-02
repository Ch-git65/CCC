namespace bite
{
    // List的节点类
    template<class T>
    struct ListNode
    {
        ListNode(const T& val = T()) : _pPre(nullptr), _pNext(nullptr), _val(val)
        {}
        ListNode<T>* _pPre;
        ListNode<T>* _pNext;
        T _val;
    };

    //List的迭代器类
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

    //list类
    template<class T>
    class list
    {
        typedef ListNode<T> Node;
        typedef Node* PNode;
    public:
        typedef ListIterator<T, T&, T*> iterator;
        typedef ListIterator<T, const T&, const T&> const_iterator;
    public:

        // List的构造
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
            // 用l中的元素构造临时的temp,然后与当前对象交换
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

        // 在pos位置前插入值为val的节点
        iterator insert(iterator pos, const T& val)
        {
            PNode pNewNode = new Node(val);
            PNode pCur = pos._pNode;
            // 先将新节点插入
            pNewNode->_pPre = pCur->_pPre;
            pNewNode->_pNext = pCur;
            pNewNode->_pPre->_pNext = pNewNode;
            pCur->_pPre = pNewNode;
            return iterator(pNewNode);
        }

        // 删除pos位置的节点，返回该节点的下一个位置
        iterator erase(iterator pos)
        {
            // 找到待删除的节点
            PNode pDel = pos._pNode;
            PNode pRet = pDel->_pNext;

            // 将该节点从链表中拆下来并删除
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
    std::list<int> l1; // 构造空的l1
    std::list<int> l2(4, 100); // l2中放4个值为100的元素
    std::list<int> l3(l2.begin(), l2.end()); // 用l2的[begin(), end()）左闭右开的区间构造l3
    std::list<int> l4(l3); // 用l3拷贝构造l4
    // 以数组为迭代器区间构造l5
    int array[] = { 16,2,77,29 };
    std::list<int> l5(array, array + sizeof(array) / sizeof(int));
    // 用迭代器方式打印l5中的元素
    for (std::list<int>::iterator it = l5.begin(); it != l5.end(); it++)
        std::cout << *it << " ";
    std::cout << endl;

    // C++11范围for的方式遍历
    for (auto& e : l5)
        std::cout << e << " ";

    std::cout << endl;
    return 0;
}