//����һ
//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);  //&a�õ�����int(*)[5],ptr�õ�����5�����Ԫ��
//	printf("%d %d", *(a+1), *(ptr-1)); // 2 5
//	return 0;
//}

//�����
//#include<stdio.h>
//struct Test {
//	int Num;
//	char *pcName;
//	short sDate;
//	char cha[2];
//	short sBA[4];
//}*p;
//int main()
//{
//	struct Test *p = (struct Test*)0x100000;
//	printf("%p\n", p+0x1);                  //00100014
//	printf("%p\n", (unsigned long)p + 0x1); //00100001 ǿ��ת��������p�ͱ����һ��unsigned long,
//	                                        //��+1����ֻ�ǵ���������+1
//	printf("%p\n", (unsigned int*)p + 0x1); //00100004
//	return 0;
//}

//������
//#include<stdio.h>
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int *ptr1 = (int*)(&a + 1);       //&a�õ�����int(*)[4],ptr�õ�����4�����Ԫ��
//	int *ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2); // 4 2.000000
//	return 0;
//}

//������
//#include<stdio.h>
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) }; //���ű��ʽ��ֻȡ���һ��������1,3,5
//	int *p;
//	p = a[0];                // a[0]ȡ����һ������Ϊ2��Ԫ�ص�һ�����飬pΪ����������Ԫ�ص�ַ      
//	printf("%d", p[0]);      // 1
//	return 0;
//}

//������
//#include<stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2]-&a[4][2], &p[4][2] - &a[4][2]); //FFFFFFFC -4
//}

//������
//#include<stdio.h>
//int main()
//{
//	int aa[2][5] = {
//    {1,2,3,4,5},
//	{6,7,8,9,10}
//	};
//	int* ptr1 = (int*)(&aa + 1);          //&aa��һ������ָ��int(*)[2][5],��+1��������������
//	int* ptr2 = (int*)(*(aa + 1));        //aa������������+1����ʽת��int(*)[5],��(int*)(aa[1])
//	printf("%d,%d", *(ptr1-1), *ptr2-1);  //10,5
//	return 0;
//}

//������ ָ������
//#include<stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);    //at
//	return 0;
//}

//�����
#include<stdio.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);         //POINT
	printf("%s\n", *-- * ++cpp + 3); //ER
	printf("%s\n", *cpp[-2] + 3);    //ST   cpp[-2] => *(cpp-2)��û���޸�cpp�����ݣ���++�����޸�
	printf("%s\n", cpp[-1][-1] + 1); //EW
	return 0;
}