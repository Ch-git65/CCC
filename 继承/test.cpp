#include <iostream>
#include <string>
using namespace std;
//
//class Person
//{
//public:
//	void Print()
//	{
//		cout << "name:" << _name << endl;
//		cout << "age:" << _age << endl;
//	}
//public:
//	int _id = 1;
//
//	//protected: ���ⲻ�ɼ������ڲ�������ɼ�
//protected:
//	string _name = "peter";
//private:
//	int _age = 18;
//};


//�̳�;  ����븴��
//class/struct ������ ��Ҫ�̳е���
//    ����/������   ����/����
class Student : public Person
	//class Student: public Person
	//class Student: private Person
	//class������࣬ Ĭ�ϼ̳з�ʽ��private
	//class Student: Person
	//strut������ࣺ Ĭ�ϼ̳з�ʽ�� public
	//struct Student: Person

//{
//public:
//	void show()
//	{
//		cout << _name << "/t" << _id << endl;
//		//����private��Ա�������в��ɼ���������ȷʵ�и���ĳ�Ա
//		//cout << _age << endl;
//	}
//	//protected:
//public:
//	int _num = 2020;
//};

//class Empty
//{};
//
//void test()
//{
//	cout << sizeof(Person) << endl;
//	cout << sizeof(Student) << endl;
//	cout << sizeof(Empty) << endl;
//
//	Person p;
//	//Print, id�ڸ����еķ���Ȩ��λpublic
//	p.Print();
//	p._id = 3;
//
//	Student st;
//	//����̳з�ʽΪprotected/private, �Ӹ���̳����������г�Ա����ͷ���Ȩ��Ϊprotected/private
////	//�����������ⲻ�ɼ�
//	st.Print();
//	st._id = 2;
//	//st._name="123";
//	//st._age = 18;
//}

//void test2()
//{
//	Person p;
//	Student st;
//
//	//��Ƭ�� �������ָ�룬���ÿ���ֱ�Ӹ�ֵ���������
//	//ָ�룬���ã� �˴�������ʽ����ת��
//	
//	p = st;
//	Person& rs = st;
//	Person* ptrs = &st;
//
//	//��������ܸ�ֵ���������
//	//st = (Student)p;
//	//����ָ�룬 ���ò���ֱ�Ӹ�ֵ������ָ�룬���á�����ͨ��ǿת����ת�������и�ֵ
//	//����ǿת����ת������ȫ�����ܻᵼ�·���Խ��
//	//һ�㲻����ǿת����ת�������ǲ��ö�̬ת��
//
//	Student& rp = (Student&)p;
//	Student* ptrp = (Student*)&p;
//
//	cout << rp._nnum << endl;
//	cout << ptrp->_num << endl;
//
//	Student& rs2 = (Student&)rs;
//	cout << rs2._num << endl;
//	Student* ptrs2 = (Student*)ptrs;
//	cout << ptrs2->_num < , endl;
//}