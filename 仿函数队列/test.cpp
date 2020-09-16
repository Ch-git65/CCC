#include<iostream>
#include<vector>
using namespace std;

template <class T>
struct Greater
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 > val2;
	}
};

template <class T>
struct Less
{
	bool operator()(const T& val1, const T& val2)
	{
		return val1 < val2;
	}
};

class Date
{
public:
	Date(int y, int m, int d)
		:_y(y), _m(m), _d(d)
	{}

	bool operator>(const Date& d) const
	{
		if (_y > d._y)
			return true;
		else if (_y == d._y)
		{
			if (_m > d._m)
				return true;
			else if (_m == d._m)
			{
				if (_d > d._d)
					return true;
			}
		}
		return false;
	}

	bool operator<(const Date& d) const
	{
		if (_y < d._y)
			return true;
		else if (_y == d._y)
		{
			if (_m < d._m)
				return true;
			else if (_m == d._m)
			{
				if (_d < d._d)
					return true;
			}
		}
		return false;
	}
public:
	int _y;
	int _m;
	int _d;
};

ostream& operator<<(ostream& cout, const Date& d)
{
	cout << d._y << "-" << d._m << "-" << d._d << endl;
	return cout;
}

template <class T, class Container = vector<T>, class Compare = Less<T>>
class Priority_Queue
{
public:
	void push(const T& val)
	{
		_c.push_back(val);
		shiftUp(_c.size() - 1);
	}

	void pop()
	{
		swap(_c[0], _c[_c.size() - 1]);
		_c.pop_back();
		shiftDown(0);
	}

	T& top()
	{
		return _c.front();
	}

	size_t size() const
	{
		return _c.size();
	}

	bool empty() const
	{
		return _c.empty();
	}

private:
	void shiftDown(int parent)
	{
		int child = 2 * parent + 1;
		while (child < _c.size())
		{
			//if (child + 1 < _c.size() && _c[child] < _c[child + 1])
			//通过仿函数实现比较的逻辑
			if (child + 1 < _c.size() && _cmp(_c[child], _c[child + 1]))
				++child;
			//if (_c[parent] < _c[child])
			if (_cmp(_c[parent], _c[child]))
			{
				swap(_c[parent], _c[child]);
				parent = child;
				child = 2 * parent + 1;
			}
			else
				break;
		}
	}

	void shiftUp(int child)
	{
		int parent = (child - 1) / 2;
		while (child > 0)
		{
			//if (_c[parent] < _c[child])
			if (_cmp(_c[parent], _c[child]))
			{
				swap(_c[parent], _c[child]);
				child = parent;
				parent = (child - 1) / 2;
			}
			else
				break;
		}
	}
private:
	Container _c;
	Compare _cmp;
};

