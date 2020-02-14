#define _CRT_SECURE_NO_WARNINGS 1

//#include<stdio.h>
//struct HAR {
//	int x, y;
//	struct HAR *p;
//}; h[2];
//void main()
//{
//	h[0].x = 1;h[0].y = 2;
//	h[1].x = 3;h[1].y = 4;
//	h[0].p = &h[1];h[1].p = h;
//	printf("%d %d\n",(h[0].p)->x,(h[1].p)->y);
//	return 0;
//}
//#define A 4+5          //A=4+5       9
//#define B A*A          //B=A*A       9+(4*5)=29
//#include<stdio.h>      //n=B*B      29+(4*5)+(4*5)=69
//int main()
//{
//	int n;
//	n = B*B;
//	printf("%d %d %d\n", A, B, n);//9 29 69
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	short i = 65537;
//	int j = i + 1;
//	printf("i=%d,j=%d\n", i, j);
//	return 0;
//}


//#include<stdio.h>
//int main()
//{
//	int a[] = { 2,4,6,8,10 }, *p, **k;
//	p = a;
//	k = &p;
//	printf("%d", *(p++));
//	printf("%d\n",**k);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int a, b, c;
//	scanf("%d %d", &a, &b);
//	c = a;
//	a = b;
//	b = c;
//	printf("a=%d b=%d\n", a, b);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int b;
//	int arr[10] = {1,2,5,9,8,7,5,6,4,2};
//	for (int i = 0; i < 10; i++) {
//		if (arr[0] < arr[i + 1]) {
//			arr[0] = arr[i + 1];
//			b = arr[0];
//		}
//		else {
//			b = arr[0];
//		}
//	}
//	printf("%d ", b);
//	return 0;
//}
//#include<stdio.h>
//int max(int x, int y)
//{
//	return x > y ? x : y;
//}
//int min(int x, int y)
//{
//	return x > y ? y : x;
//}
//int main()
//{
//	int a=3, b=6, c=4;
//	a = max(a, b);
//	a = max(a, c);
//	c = min(c, b);
//	c = min(c, a);
//	printf("%d %d %d\n", a, b, c);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int m=0;
//	for (int i = 1; i <= 100; i++) {
//		m += i;
//	}
//	printf("%d ", m);
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	if (n % 3 == 0 && n % 5 == 0)
//		printf("能别整除\n");
//	else
//		printf("不能\n");
//	return 0;
//}

//素数
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	for (int i = 100; i<201; i++)
//	{
//		int m = sqrt(i);
//		for (int n = 2; n < m ; n++) {
//			if (i%n == 0)
//				break;
//				printf("%d ", i);
//		}
//	}
//	return 0;
//}

//最大公约数
//#include<stdio.h>
//int main()
//{
//	int m , n;
//	int i,j;
//	printf("input m n:");
//	scanf("%d %d", &m, &n);
//	if (m > n) i = m;
//	else i = n;
//	int a = 1;
//	while (a <= i)
//	{
//		if (m%a == 0 && n%a == 0)
//			j = a;
//		a++;
//	}
//	printf("%d\n", j);
//	return 0;
//}

//求方程解
//#include<stdio.h>
//#include<math.h>
//int main()
//{
//	float a, b, c;
//	float x1,x2,x;
//	printf("输入abc:");
//	scanf("%f %f %f", &a, &b, &c);
//	x1 = (sqrt(b*b - 4 * a*c) + b) / 2 * a;
//	x2 = (sqrt(b*b - 4 * a*c) - b) / 2 * a;
//	if (x1 = x2) {
//		x = x1;
//		printf("%f\n", x);
//	}
//	else
//		printf("%f %f\n", x1, x2);
//	return 0;
//}
//闰年
#include<stdio.h>
int main()
{
	for (int i = 1900; i <= 2000; i++)
	{
		if ((i % 4 == 0 && i % 100 != 0)||i%400 ==0)
		printf("%d ", i);
	}
	return 0;
}