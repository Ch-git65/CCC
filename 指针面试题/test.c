//问题一
//#include<stdio.h>
//int main()
//{
//	int a[5] = { 1,2,3,4,5 };
//	int* ptr = (int*)(&a + 1);  //&a得到的是int(*)[5],ptr得到的是5后面的元素
//	printf("%d %d", *(a+1), *(ptr-1)); // 2 5
//	return 0;
//}

//问题二
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
//	printf("%p\n", (unsigned long)p + 0x1); //00100001 强制转换，导致p就变成了一个unsigned long,
//	                                        //再+1，就只是单纯的整数+1
//	printf("%p\n", (unsigned int*)p + 0x1); //00100004
//	return 0;
//}

//问题三
//#include<stdio.h>
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int *ptr1 = (int*)(&a + 1);       //&a得到的是int(*)[4],ptr得到的是4后面的元素
//	int *ptr2 = (int*)((int)a + 1);
//	printf("%x,%x", ptr1[-1], *ptr2); // 4 2.000000
//	return 0;
//}

//问题四
//#include<stdio.h>
//int main()
//{
//	int a[3][2] = { (0,1),(2,3),(4,5) }; //逗号表达式，只取最后一个数，即1,3,5
//	int *p;
//	p = a[0];                // a[0]取到了一个长度为2个元素的一堆数组，p为这个数组的首元素地址      
//	printf("%d", p[0]);      // 1
//	return 0;
//}

//问题五
//#include<stdio.h>
//int main()
//{
//	int a[5][5];
//	int(*p)[4];
//	p = a;
//	printf("%p,%d\n", &p[4][2]-&a[4][2], &p[4][2] - &a[4][2]); //FFFFFFFC -4
//}

//问题六
//#include<stdio.h>
//int main()
//{
//	int aa[2][5] = {
//    {1,2,3,4,5},
//	{6,7,8,9,10}
//	};
//	int* ptr1 = (int*)(&aa + 1);          //&aa是一个数组指针int(*)[2][5],再+1，跳过整个数组
//	int* ptr2 = (int*)(*(aa + 1));        //aa是数组名，再+1，隐式转成int(*)[5],即(int*)(aa[1])
//	printf("%d,%d", *(ptr1-1), *ptr2-1);  //10,5
//	return 0;
//}

//问题七 指针数组
//#include<stdio.h>
//int main()
//{
//	char* a[] = { "work","at","alibaba" };
//	char** pa = a;
//	pa++;
//	printf("%s\n", *pa);    //at
//	return 0;
//}

//问题八
#include<stdio.h>
int main()
{
	char* c[] = { "ENTER","NEW","POINT","FIRST" };
	char** cp[] = { c + 3,c + 2,c + 1,c };
	char*** cpp = cp;
	printf("%s\n", **++cpp);         //POINT
	printf("%s\n", *-- * ++cpp + 3); //ER
	printf("%s\n", *cpp[-2] + 3);    //ST   cpp[-2] => *(cpp-2)并没有修改cpp的内容，而++操作修改
	printf("%s\n", cpp[-1][-1] + 1); //EW
	return 0;
}