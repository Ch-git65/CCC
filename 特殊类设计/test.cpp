//ֻ�ڶ��ϴ����������

// ���캯��˽��
// �ṩһ����̬�Ķ��ϴ�������ķ���
// ������  ������������Ϊ˽�У��Ҳ�ʵ�֣�������Ϊdelete�ĺ���

class HeapOnly
{
public:
	static HeapOnly* getInstance()
	{
		//���ϴ�������
		return new HeapOnly;
	}

private:
	HeapOnly()
	{}

	//HeapOnly(const HeapOnly& ho);
	HeapOnly(const HeapOnly& ho) = delete;
};

//HeapOnly g;
void test()
{
	//HeadOnly ho;
	HeapOnly* ptr = HeapOnly::getInstance();

	//HeapOnly copy(*ptr);
}


//ֻ��ջ�ϴ����������
// ���캯��˽��
// �ṩһ�����еľ�̬��ջ�ϴ�������ķ���
class StaclOnly
{
public:
	static StaclOnly getInstance()
	{
		return StaclOnly();
	}
private:
	StaclOnly()
	{};
};

//StackOnly so;
void testStackOnly()
{
	//StackOnly* ptr = new StackOnly;
	StaclOnly so = StaclOnly::getInstance();
}

// 2
// ���캯��˽��
// �ṩһ�����еľ�̬��ջ�ϴ�������ķ���
// ��operator new��������Ϊdelete����
class StaclOnly2
{
public:
	static StaclOnly2 getInstance()
	{
		return StaclOnly2();
	}

	void* operator new(size_t n) = delete;
private:
	StaclOnly2() {};
};


//��ֹ��������
// ��������͸�ֵ���������Ϊdelete������ ������Ϊ˽�У��Ҳ�ʵ��
class NoCopy
{
public:
	NoCopy() {};
private:

	NoCopy(const NoCopy& nc) = delete;
	NoCopy& operator=(const NoCopy& nc) = delete;
};

//���ܱ��̳е���
// ����Ĺ�������Ϊ˽��
class NoH
{
private:
	NoH() {};
};

class NoH2 final
{};

//class sub : public NoH
class sub /*:public NoH2*/
{

};
