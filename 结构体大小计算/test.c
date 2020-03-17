//#include<stdio.h>
//struct s1
//{
//	char c1;
//	int i;
//	char c2;
//};
//struct s2
//{
//	char c1;
//	char c2;
//	int i;
//};
//struct s3
//{
//	double d;
//	char c;
//	int i;
//};
////嵌套
//struct s4
//{
//	char c1;
//	struct s3 s3;
//	double d;
//};
//int main() {
//	printf("%d\n", sizeof(struct s1));//12
//	printf("%d\n", sizeof(struct s2));//8
//	printf("%d\n", sizeof(struct s3));//16
//	printf("%d\n", sizeof(struct s4));//32
//	return 0;
//}

//修改默认对齐数
//#include<stdio.h>
//#pragma pack(8)  //设置默认对齐数为8
//struct s1
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//
//#pragma pack(1)
//struct s2
//{
//	char c1;
//	int i;
//	char c2;
//};
//#pragma pack()
//int main()
//{
//	printf("%d\n", sizeof(struct s1));//12
//	printf("%d\n", sizeof(struct s2));//6
//	return 0;
//}

//#include<stdio.h>
//
//struct S
//{
//	int data[1000];
//	int num;
//};
//
//struct S s = { {1,2,3,4},1000 };
////结构体传参
//void print1(struct S s)
//{
//	printf("%d\n", s.num);
//}
////结构体地址传参
//void print2(struct S* ps)
//{
//	printf("%d\n", ps->num);
//}
//int main() {
//	print1(s);  //1000
//	print2(&s); //1000
//	return 0;
//}

//#include<stdio.h>
//struct A
//{
//	int _a : 2;
//	int _b : 5;
//	int _c : 10;
//	int _d : 30;
//};
//int main()
//{
//	printf("%d\n", sizeof(struct A)); //8
//}
