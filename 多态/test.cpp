#include <iostream>
using namespace std;


//��̬
//1. �̳�
//2. �麯���� ��������麯������д
//3. �����麯�������ͱ�����ָ��/����, һ�㶼���ø�ָ��/����ָ�����Լ�����ʵ��


class A
{};

class B : public A
{

};

class Person {
public:
	Person()
	{
		cout << "����Person�������Դ" << endl;
	}
	virtual void BuyTicket() {
		cout << "��Ʊ-ȫ��" << endl;
	}

	virtual ~Person()
	{
		cout << "����Person������Դ" << endl;

	}
};

class Student : public Person {
public:
	Student()
	{
		cout << "����Student�����¼ӵ���Դ" << endl;
	}

	//�麯������д����д�����߼�
	//�����麯������д���������ຬ�к͸���ӿ���ȫ��ͬ�ĺ���

	virtual void BuyTicket(int a = 10) {
		cout << "��Ʊ-���" << endl;
		
	}

	//Э�䣺����ֵ���Ϳ��Բ�ͬ�����Ƿ���ֵ���ͱ����Ǹ��ӹ�ϵ��ָ������
	/*virtual B& BuyTicket() {
		cout << "��Ʊ-���" << endl;
		return B();
	}*/

	//�������������͸������������ײ�ͬ��������ֻҪ�����������麯�����������������¸�������
	~Student()
	{
		cout << "����Student�����¼ӵ���Դ" << endl;
	}
};