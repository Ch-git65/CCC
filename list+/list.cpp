#include <iostream>
using namespace std;

template < class T >
struct ListNode
{
	T _value;
	ListNode<T>* _next;
	ListNode<T>* _prev;

	ListNode(const T& val = T())
		:_value(val)
		, _next(nullptr)
		, _prev(nullptr)
	{}
};

template<class T, class Ref, class Ptr>
struct ListIterator
{
	typedef ListNode<T> Node;
	typedef ListIterator<T, Ref, Ptr> Self;

	ListIterator(Node* node)
		:_node(node)
	{}

	//解引用
	Ref operator*()
	{
		return _node->_value;
	}

	//指针->成员
	Ptr operator->()
	{
		return &_node->_value;
	}

	Self& operator++()
	{
		_node = _node->_next;
		return *this;
	}

	Self& operator--()
	{
		_node = _node->_prev;
		return *this;
	}

	bool operator!=(const Self& it)
	{
		return _node != it._node;
	}

	Node* _node;

};

template <class T>
class List
{
public:
	typedef ListNode<T> Node;

	typedef ListIterator<T, T&, T*> iterator;

	//不能通过添加const修饰符来定义const

	typedef ListIterator<T, const T&, const T*> const_iterator;

	iterator beggin()
	{
		return iterator(_header->_next);
	}

	iterator end()
	{
		return iterator(_header);
	}

	const_iterator begin() const
	{
		return const_iterator(_header->_next);
	}

	const_iterator end() const
	{
		return const_iterator(_header);
	}

	List()
		:_header(new Node)
	{
		//构建循环结构
		_header->_next = _header->prev;
	}

	void pushBack(const T& val)
	{
		/*Node* cur = new Node(val);

		Node* prev = _header->_prev;

		prev->_next = cur;
		cur->_prev = prev;

		cur->_next = _header;
		_header->_prev = cur;*/

		insert(end(), val);
	}
	
	void pushFront(const T& val)
	{
		insert(begin(), val);
	}

	void popBack()
	{
		erase(--end());
	}

	void popFront()
	{
		erase(begin());
	}

	void insert(iterator pos, const T& val)
	{
		Node* cur = new Node(val);

		Npde* node = pos._node;
		Node* prev = node->_prev;

		prev->_next = cur;
		cur->_prev = prev;
	
		cur->_next = node;
		node->_prev = cur;
	}

	//删除导致迭代器失效
	itrator erase(iterator pos)
	{
		if (pos != end())
		{
			Node* node = pos._node;
			Node* prev = node->_prev;
			Node* next = node->_next;

			delete node;

			prev->_next = next;
			next->_prev = prev;
			return iterator(next);
		}
		return pos;
	}

	size_t size() const
	{
		size_t count = 0;
		for (const auto& e : *this)
			++count;
		return count;
	}

	~List()
	{
		if (_header)
		{
			clear();
			delete _header;
			_header = nullptr;
		}
	}

	void clear()
	{
		Node* cur = _header->_next;
		while (cur != _header)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
		_header->_next = _header->_prev=_header;
	}

	List(const List<T>& lst)
		:_header(new Node)
	{
		_header->_next = _header->_prev=_header;
		for (const auto& e : lst)
			pushBack(e);
	}

	List<T>& operator=(List<T>& lst)
	{
		swap(_header, lst._header);
		return *this;
	}
};